from lexer import Lexer
import parser_tree as p
from pprint import pprint


class TableGenerator:
    def __init__(self):
        self.grammar = {}
        self.start_symbol = None
        self.non_terminals = set()
        self.right_nonterms = set()
        self.terminals = set()
        self.first = None
        self.follow = None
        self.table = None

    def _tree_to_grammar(self, tree: p.Inner, terminals: set[str]):
        self.terminals = terminals
        self.expand_grammar(tree)

        self.check_grammar()

    def check_grammar(self):
        if not self.start_symbol:
            raise ValueError('No axiom')
        if not self.right_nonterms.issubset(self.non_terminals):
            raise ValueError('Right grammar part not in nonterminals')

    def expand_grammar(self, tree: p.Inner):
        self.expand_rule(tree.children[0])
        self.expand_rules(tree.children[1])

    def expand_rule(self, tree: p.Inner):
        left = self.expand_left(tree.children[0])
        right = self.expand_right(tree.children[2])
        self.grammar[left] = right

    def expand_rules(self, tree: p.Inner):
        if len(tree.children) == 1:
            return

        self.expand_rule(tree.children[0])
        self.expand_rules(tree.children[1])

    def expand_left(self, tree: p.Inner):
        nonterm = tree.children[2].children[0].get_name()
        self.non_terminals.add(nonterm)
        self.expand_axiom(tree.children[1], nonterm)
        return nonterm

    def expand_right(self, tree: p.Inner):
        right = tuple(self.expand_part_right(tree.children[0]))
        if len(right) == 0:
            right = ('eps',)
        other = self.expand_alternative(tree.children[1])
        return {right} | other

    def expand_axiom(self, tree: p.Inner, nonterm):
        if tree.children[0].get_name() == 'eps':
            return

        if self.start_symbol:
            raise ValueError('Multiple axioms')
        self.start_symbol = nonterm

    def expand_part_right(self, tree: p.Inner):
        res = []
        for child in tree.children:
            if isinstance(child, p.Leaf) or child.children[0].get_name() == 'eps':
                continue

            if child.get_name() == 'PART_RIGHT':
                res.extend(self.expand_part_right(child))
                continue

            if child.get_name() == 'NONTERM' and child.children[0].get_name() not in self.terminals:
                self.right_nonterms.add(child.children[0].get_name())

            res.append(child.children[0].get_name())

            if child.get_name() == 'TERM':
                self.terminals.add(child.children[0].get_name())

        return res

    def expand_alternative(self, tree: p.Inner):
        if tree.children[0].get_name() == 'eps':
            return set()

        part = tuple(self.expand_part_right(tree.children[1]))
        if len(part) == 0:
            part = ('eps',)
        other = self.expand_alternative(tree.children[2])

        return {part} | other

    def is_ll1(self):
        for nt, row in self.table.items():
            seen = set()
            for terminal, production in row.items():
                if production:
                    if (nt, terminal) in seen:
                        return False
                    seen.add((nt, terminal))
        return True

    def compute_first(self, terminals):
        first = {nt: set() for nt in self.grammar}

        def first_of(symbol):
            if symbol not in self.grammar:
                return {symbol}
            if not first[symbol]:
                for production in self.grammar[symbol]:
                    for sym in production:
                        sym_first = first_of(sym)
                        first[symbol].update(sym_first - {'eps'})
                        if 'eps' not in sym_first:
                            break
                    else:
                        first[symbol].add('eps')
            return first[symbol]

        for nonterm in self.grammar:
            first_of(nonterm)

        for term in terminals:
            first[term] = {term}

        return first

    def compute_follow(self, terminals):
        follow = {nt: set() for nt in self.grammar}
        follow[self.start_symbol].add('$')

        first = self.compute_first(terminals)

        def follow_of(nonterm):
            for nt, productions in self.grammar.items():
                for production in productions:
                    if nonterm in production:
                        index = production.index(nonterm)
                        follow_set = set()
                        for sym in production[index + 1:]:
                            sym_first = first[sym]
                            follow_set.update(sym_first - {'eps'})
                            if 'eps' in sym_first:
                                continue
                            else:
                                break
                        else:
                            if nt != nonterm:
                                follow_set.update(follow_of(nt))
                        follow[nonterm].update(follow_set)
            return follow[nonterm]

        for nt in self.grammar:
            follow_of(nt)

        return follow

    def generate_table(self, tree: p.Inner, terminals: set[str]):
        self._tree_to_grammar(tree, terminals)
        self.follow = self.compute_follow(self.terminals)
        self.first = self.compute_first(self.terminals)

        table = {nt: {t: None for t in terminals | {'$'}} for nt in self.grammar}

        for nt, productions in self.grammar.items():
            for production in productions:
                if production == ('eps',):
                    for terminal in self.follow[nt]:
                        table[nt][terminal] = production
                else:
                    for symbol in production:
                        if symbol in terminals:
                            table[nt][symbol] = production
                            break
                        else:
                            for t in self.first[symbol]:
                                if t != 'eps':
                                    table[nt][t] = production
                            if 'eps' not in self.first[symbol]:
                                break
                    else:
                        for terminal in self.follow[nt]:
                            table[nt][terminal] = production

        self.table = table

        if not self.is_ll1():
            raise ValueError('Not LL1 grammar')

        return self.table

    def refactor_table(self, terminals_mapping):
        new_table = {}
        for nt, row in self.table.items():
            for k, v in row.items():
                if v:
                    new_table[(nt, terminals_mapping[k])] = v if v != ('eps',) else 'eps'

        self.table = new_table
        return self.table

    def get_table(self):
        return self.table


if __name__ == '__main__':
    mapping = {"'or": 'KW_OR',
               "'end": 'KW_END',
               "'epsilon": 'KW_EPS',
               "'axiom": "KW_AXIOM",
               "->": 'ARROW',
               "STR_TERM": "STR_TERM",
               "NONTERM": "NONTERM",
               "(": "LPAREN",
               ")": "RPAREN",
               "+": "PLUS",
               "-": "MINUS",
               "*": "MUL",
               "NUM": "NUM",
               }
    lexer = Lexer('grammar_new.txt')
    parser = p.Parser(lexer)
    tree = parser.top_down_parse('GRAMMAR')
    tree.print()
    table_gen = TableGenerator()
    table_gen.generate_table(tree, {'TERM', 'NONTERM'})
    table = table_gen.refactor_table(mapping)
    # pprint(table)
    pprint(table_gen.grammar)
