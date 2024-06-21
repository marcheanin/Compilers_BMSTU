import abc
from itertools import count
from lexer import Lexer

iid = count()


class Node(abc.ABC):
    def print(self, num: int):
        pass

    def get_name(self):
        pass


class Leaf(Node):
    def __init__(self, token):
        self.token = token

    def get_name(self):
        if self.token[1][0] == '\\':
            return self.token[1][1]
        return self.token[1]

    def print(self, num: int):
        print(f'{num} [label="{self.token[1]}"];')


class Inner(Node):
    def __init__(self, nterm: str = None, rule_id: int = None, children: list[Node] = None):
        self.nterm = nterm
        self.rule_id = rule_id
        if children is None:
            self.children = []
        else:
            self.children = children

    def get_name(self):
        return self.nterm

    def print(self, num: int = None):
        if num is None:
            nterm_num = next(iid)
        else:
            nterm_num = num

        print(f'{nterm_num} [label="{self.nterm}"];')

        for child in self.children:
            child_num = next(iid)
            print(f'{nterm_num} -> {child_num}')
            child.print(child_num)


class Parser:
    def __init__(self, lexer, table=None, terminals=None):
        self.lexer = lexer
        if not table:
            self.table = {
                ('GRAMMAR', 'KW_AXIOM'): ['RULE', 'GRAMMAR'],
                ('GRAMMAR', 'NONTERM'): ['RULE', 'GRAMMAR'],
                ('GRAMMAR', 'END'): 'eps',

                ('RULE', 'KW_AXIOM'): ['LEFT', 'ARROW', 'RIGHT', 'KW_END'],
                ('RULE', 'NONTERM'): ['LEFT', 'ARROW', 'RIGHT', 'KW_END'],

                ('LEFT', 'KW_AXIOM'): ['KW_AXIOM', 'NONTERM'],
                ('LEFT', 'NONTERM'): ['NONTERM'],

                ('RIGHT', 'NONTERM'): ['PART_RIGHT', 'ALTERNATIVE'],
                ('RIGHT', 'KW_EPS'): ['PART_RIGHT', 'ALTERNATIVE'],
                ('RIGHT', 'STR_TERM'): ['PART_RIGHT', 'ALTERNATIVE'],

                ('ALTERNATIVE', 'KW_OR'): ['KW_OR', 'PART_RIGHT', 'ALTERNATIVE'],
                ('ALTERNATIVE', 'KW_END'): 'eps',

                ('PART_RIGHT', 'NONTERM'): ['SYMB', 'PART_RIGHT2'],
                ('PART_RIGHT', 'KW_EPS'): ['KW_EPS'],
                ('PART_RIGHT', 'STR_TERM'): ['SYMB', 'PART_RIGHT2'],

                ('PART_RIGHT2', 'NONTERM'): ['SYMB', 'PART_RIGHT2'],
                ('PART_RIGHT2', 'STR_TERM'): ['SYMB', 'PART_RIGHT2'],
                ('PART_RIGHT2', 'KW_END'): 'eps',
                ('PART_RIGHT2', 'KW_OR'): 'eps',

                ('SYMB', 'NONTERM'): ['NONTERM'],
                ('SYMB', 'STR_TERM'): ['STR_TERM'],

            }
        else:
            self.table = table

        if not terminals:
            self.terminals = {'ARROW', 'KW_AXIOM', 'KW_OR', 'KW_END', 'KW_EPS', 'NONTERM', 'STR_TERM'}
        else:
            self.terminals = terminals

    def top_down_parse(self, axiom: str) -> Inner:
        sparent = Inner()
        s = [(sparent, '$'), (sparent, axiom)]
        a = self.lexer.next_token()

        while True:
            parent, X = s[-1]
            if X == '$':
                break
            if X in self.terminals:
                if X == a[0]:
                    s.pop()
                    inner = Inner(X, -1, [Leaf(a)])
                    parent.children.append(inner)
                    a = self.lexer.next_token()
                elif X == a[1]:
                    s.pop()
                    parent.children.append(Leaf(a))
                    a = self.lexer.next_token()
                else:
                    raise SyntaxError(f'{a[2]} expected {X} but got {a[0]}: {a[1]}')
            elif (X, a[0]) in self.table:
                if self.table[(X, a[0])] != 'eps':
                    s.pop()
                    inner = Inner(X, list(self.table.keys()).index((X, a[0])), [])
                    parent.children.append(inner)
                    for el in reversed(self.table[(X, a[0])]):
                        s.append((inner, el))
                else:
                    s.pop()
                    inner = Inner(X, -1, [Leaf((X, 'eps', (-1, -1)))])
                    parent.children.append(inner)
            else:
                raise SyntaxError(f'{a[2]} expected {X} but got {a[0]}: {a[1]}')

        return sparent.children[0]


if __name__ == "__main__":
    file_path = "grammar_new.txt"
    lexer = Lexer(file_path)
    parser = Parser(lexer)
    tree = parser.top_down_parse('GRAMMAR')
