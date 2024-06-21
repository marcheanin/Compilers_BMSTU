% Лабораторная работа № 3.1 «Самоприменимый генератор компиляторов
  на основе предсказывающего анализа»
% 21 июня 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является изучение алгоритма построения таблиц предсказывающего анализатора.

# Индивидуальный вариант
```
# ключевые слова
# начинаются с кавычки

F  -> "n" 'or "(" E ")" 'end
T  -> F T1 'end
T1 -> "*" F T1 'or 'epsilon 'end
'axiom E  -> T E1 'end
E1 -> "+" T E1 'or 'epsilon 'end
```

# Грамматика на входном языке

```
'axiom S -> K S 
        'or 'epsilon 
        'end
K -> L "ARROW" R "KW_END" 'end
L -> "KW_AXIOM" "NONTERM" 
        'or "NONTERM" 
        'end
R -> F A T 'end
T -> "KW_OR" F A T 
         'or 'epsilon 
         'end
A -> "KW_EPS" A 
        'or "NONTERM" A 
        'or "STR_TERM" A 
        'or 'epsilon 
        'end
F -> "KW_EPS" 
        'or "NONTERM" 
        'or "STR_TERM" 
        'end
```

# Реализация
## Генератор компиляторов

compiler_main.py
```python
from lexer import Lexer
from topDawnParser import topDawnParse
from tree import get_rules
from table_builder import build_table
from generated_table import table
from terms import *


def main():
    l = Lexer('grammar_new.txt')
    lexems, errors = l.parse()
    if errors:
        print("Errors:", errors[0])
        return

    root = topDawnParse(lexems, TerminalsSet, table)

    with open('graph.dot', 'w') as f:
        f.write('digraph {\n')
        root.print_graph(f)
        f.write('}')

    rules = get_rules(root)
    for x in rules:
        print(x)

    build_table(rules)


if __name__ == '__main__':
    main()
```

lexer.py
```python
import re
from terms import *

class Lexer:
    def __init__(self, filename):
        with open(filename, 'r') as file:
            self.lines = file.readlines()
        for idx, line in enumerate(self.lines):
            print(f"{idx} : {line}", end='')
        print()

    def skip_whitespace(self):
        trimmed_line = self.line.lstrip()
        self.i += len(self.line) - len(trimmed_line)
        self.line = trimmed_line

    def advance(self, substring):
        self.i += len(substring)
        self.line = self.line[len(substring):]

    def parse(self):
        errors = []
        tokens = []

        patterns = [
            (KW_AXIOM, r'^\'axiom'),
            (KW_EPS, r'^\'epsilon'),
            (KW_END, r'^\'end'),
            (KW_OR, r'^\'or'),
            (NONTERM, r'^[A-Z][A-Z0-9]*'),
            (ARROW, r'^->'),
            (STR_TERM, r'^\"[^\"]*\"'),
            (COMMENT, r'^#[^\n]*')
        ]

        for line_num, line in enumerate(self.lines):
            self.line = line.rstrip()
            self.i = 0
            while self.line:
                if self.line[0].isspace():
                    self.skip_whitespace()
                    continue

                for token_type, regex in patterns:
                    match = re.match(regex, self.line)
                    if match:
                        result = match.group(0)
                        if token_type != COMMENT:
                            tokens.append((token_type, (line_num + 1, self.i), result.strip()))
                            print((token_type, (line_num + 1, self.i), result.strip()))
                        self.advance(result)
                        break
                else:
                    print(f'error {(line_num + 1, self.i)} {self.line}')
                    errors.append((line_num + 1, self.i))
                    self.advance(' ')
        return tokens, errors
```

table_builder.py
```python
from itertools import chain
from tree import Table
from copy import deepcopy

FIRST = {}
FOLLOW = {}
EPSILON = 'eps$'
EOF = 'EOF'

def extract_axiom(rules):
    axioms = {rule.left for rule in rules if rule.is_axiom}
    print('-> FOUND SOME AXIOMS:', axioms)
    if not axioms:
        raise Exception('Нет входного правила')
    if len(axioms) > 1:
        raise Exception('Несколько входных правил')
    return axioms.pop()

def validate_productivity(rules):
    lefts = {rule.left for rule in rules}
    all_rights = set(chain.from_iterable(rule.alts for rule in rules))
    right_nonterms = {r for r in all_rights if r.is_nterm()}
    print(lefts)
    print(right_nonterms)
    if right_nonterms - lefts:
        raise Exception(f"Есть не порождающие терминалы: {right_nonterms - lefts}")

def compute_first_sets(rules):
    global FIRST
    nonterminals = {rule.left for rule in rules}

    for nt in nonterminals:
        FIRST[nt] = set()

    for rule in rules:
        FIRST[rule.left].update(calculate_first_sequence(rule.alts))

    while True:
        old_first = deepcopy(FIRST)
        for rule in rules:
            FIRST[rule.left].update(calculate_first_sequence(rule.alts) - {EPSILON})
        if old_first == FIRST:
            break

def calculate_first_sequence(sequence):
    if not sequence:
        return {EPSILON}

    head, tail = sequence[0], sequence[1:]

    if not head.is_nterm():
        return {head}

    if EPSILON not in FIRST[head]:
        return FIRST[head]

    return FIRST[head] - {EPSILON} | calculate_first_sequence(tail)

def compute_follow_sets(rules, start_symbol):
    global FOLLOW
    nonterminals = {rule.left for rule in rules}

    for nt in nonterminals:
        FOLLOW[nt] = set()

    FOLLOW[start_symbol] = {EOF}

    for rule in rules:
        for idx, symbol in enumerate(rule.alts):
            if symbol.is_nterm():
                remaining_seq = rule.alts[idx + 1:]
                FOLLOW[symbol].update(calculate_first_sequence(remaining_seq) - {EPSILON})

    print(FOLLOW)

    while True:
        old_follow = deepcopy(FOLLOW)
        for rule in rules:
            lhs = rule.left
            for idx, symbol in enumerate(rule.alts):
                if symbol.is_nterm():
                    if EPSILON in calculate_first_sequence(rule.alts[idx + 1:]):
                        FOLLOW[symbol].update(FOLLOW[lhs])
        if old_follow == FOLLOW:
            break

def generate_parsing_table(rules):
    axiom = extract_axiom(rules)
    validate_productivity(rules)
    compute_first_sets(rules)
    compute_follow_sets(rules, axiom)
    for nonterm, first_set in FIRST.items():
        print('   ', nonterm, '->', first_set)
    for nonterm, follow_set in FOLLOW.items():
        print('   ', nonterm, '->', follow_set)
    table = create_parsing_table(rules)
    table.to_file()
    return table

def create_parsing_table(rules):
    lefts = {rule.left for rule in rules}
    all_rights = set(chain.from_iterable(rule.alts for rule in rules))
    right_nonterms = {r for r in all_rights if r.is_nterm()}
    nonterminals = lefts | right_nonterms
    terminals = all_rights - right_nonterms
    print(terminals, nonterminals)
    table = Table(nonterminals, terminals | {EOF})

    for rule in rules:
        lhs, rhs = rule.left, rule.alts
        for terminal in calculate_first_sequence(rhs) - {EPSILON}:
            table.add(lhs, terminal, rhs)
            print('adding', lhs, terminal, rhs)
        if EPSILON in calculate_first_sequence(rhs):
            for follow_symbol in FOLLOW[lhs]:
                table.add(lhs, follow_symbol, rhs)

    return table
```

topDownParser.py
```python
from terms import *
from tree import TreeNode

def topDawnParse(tokens, terminal_set, parse_table):
    tokens.append((EOF, -1, -1))
    root = TreeNode(S)
    stack = [TreeNode(EOF), root]
    parsed_result = []

    current_token, remaining_tokens = tokens[0], tokens[1:]
    while True:
        top_of_stack, stack = stack[-1], stack[:-1]
        if top_of_stack.content == EOF == current_token[0]:
            return root
        if top_of_stack.content in terminal_set:
            if top_of_stack.content == current_token[0]:
                top_of_stack.content = current_token[2]
                current_token, remaining_tokens = remaining_tokens[0], remaining_tokens[1:]
            else:
                raise Exception(f'Expected {current_token[0]}, but found {top_of_stack.content}')
        elif (top_of_stack.content, current_token[0]) in parse_table:
            children_nodes = [TreeNode(symbol) 
                              for symbol in parse_table[(top_of_stack.content, current_token[0])]]
            for child in reversed(children_nodes):
                top_of_stack.addChild(child)
                stack.append(child)
            parsed_result.append((top_of_stack, parse_table[(top_of_stack.content, current_token[0])]))
        else:
            print(top_of_stack.content, type(top_of_stack.content), current_token[0])
            print(parse_table.keys())
            raise Exception(f'Unexpected element: {(top_of_stack.content, current_token[0])}')

```

tree.py
```python
class ParsingTable:
    def __init__(self, nonterminals, terminals):
        self.error_entry = ['ERROR']
        self.table = {(n, t): self.error_entry for t in terminals for n in nonterminals}

    def add_rule(self, nonterminal, terminal, production):
        if self.table[(nonterminal, terminal)] == self.error_entry:
            self.table[(nonterminal, terminal)] = production
        else:
            raise Exception(f'Not LL(1): Conflict at {(nonterminal, terminal)}')

    def save_to_file(self, filename='generated_table2.py'):
        with open(filename, 'w') as f:
            f.write('table = {\n')
            for key, value in self.table.items():
                print(key, value)
                if value == self.error_entry:
                    continue
                n, t = key[0], key[1]
                n = f'"{n}"'
                t = f'"{str(t)}"'
                value = [str(v).replace('"', '') for v in value]
                f.write(f'    ({n}, {t}) : {value}, \n')
            f.write('}\n')

unique_id = 0

class SyntaxTreeNode:
    def __init__(self, content):
        global unique_id
        unique_id += 1
        self.content = content
        self.children = []
        self.id = unique_id

    def add_child(self, child):
        self.children.insert(0, child)

    def __repr__(self):
        return str(self.content)

    def print_graph(self, f):
        f.write(f'{self.id} [label = "{self.id} {str(self.content)}"]\n')
        for child in self.children:
            f.write(f'{self.id} -> {child.id}\n')
        for child in self.children:
            child.print_graph(f)

    def __len__(self):
        return len(self.children)

    def __getitem__(self, index):
        return self.children[index]

    def __eq__(self, other):
        return isinstance(other, SyntaxTreeNode) and self.content == other.content

    def __hash__(self):
        return hash(self.content)

    def is_nonterminal(self):
        return 'A' <= self.content[0] <= 'Z'

class GrammarRule:
    def __init__(self, left_side, is_start, right_sides):
        self.left_side = left_side
        self.is_start = is_start
        self.right_sides = right_sides

    def __str__(self):
        return f'{"[START]: " if self.is_start else ""}{self.left_side} -> {self.right_sides}'

    def __repr__(self):
        return str(self)

def extract_rules(root):
    if not root:
        return []
    assert len(root) == 2
    rule_node, rules_node = root[0], root[1]
    rule = extract_rule(rule_node)
    return rule + extract_rules(rules_node)

def extract_rule(root):
    assert len(root) == 4
    left, is_start = extract_left_side(root[0])
    right_sides = extract_right_side(root[2])
    return [GrammarRule(left, is_start, [symbol for symbol in alt 
                                         if symbol.content != "'epsilon"]) for alt in right_sides]

def extract_left_side(root):
    if len(root) == 1:
        return root[0], False
    return root[1], True

def extract_right_side(root):
    first, rest, tail = root[0], root[1], root[2]
    alt1 = [first[0]] + extract_symbols(rest)
    other_alts = extract_right_side_alternatives(tail)
    return [alt1] + other_alts

def extract_symbols(root):
    if not root:
        return []
    return [root[0]] + extract_symbols(root[1])

def extract_right_side_alternatives(root):
    if not root:
        return []
    first, rest, tail = root[1], root[2], root[3]
    alt1 = [first[0]] + extract_symbols(rest)
    other_alts = extract_right_side_alternatives(tail)
    return [alt1] + other_alts

```

## Калькулятор

Грамматика:
```
'axiom S -> T E 'end
E -> S1 T E 'or 'epsilon 'end
T -> F T2 'end
T2 -> S2 F T2 'or 'epsilon 'end
F -> "NUM" 'or "(" S ")" 'end
S1 -> "/" 'or "*" 'end
S2 -> "-" 'or "+" 'end
```

calc_lexer.py
```python
import re

class Lexer:
    def __init__(self, file_name):
        with open(file_name, 'r') as f:
            self.lines = f.readlines()
        for i, line in enumerate(self.lines):
            print(f"{i} : {line}", end='')
        print()

    def _skip_spaces(self):
        new_line = self.line.lstrip()
        self.i += len(self.line) - len(new_line)
        self.line = new_line

    def _skip(self, s):
        self.i += len(s)
        self.line = self.line[len(s):]

    def parse(self):
        lexems, errors = [], []

        token_patterns = [
            ("(", r'^\('),
            (")", r'^\)'),
            ("+", r'^\+'),
            ("-", r'^\-'),
            ("*", r'^\*'),
            ("/", r'^\/'),
            ("NUM", r'^[0-9]+'),
        ]

        for linenum, line in enumerate(self.lines):
            self.line = line.rstrip()
            self.i = 0
            while self.line:
                if self.line[0].isspace():
                    self._skip_spaces()
                    continue

                for token_type, pattern in token_patterns:
                    match = re.match(pattern, self.line)
                    if match:
                        value = match.group(0)
                        lexems.append((token_type, (linenum + 1, self.i), value.strip()))
                        print((token_type, (linenum + 1, self.i), value.strip()))
                        self._skip(value)
                        break
                else:
                    errors.append((linenum + 1, self.i))
                    print('error', (linenum + 1, self.i), self.line)
                    self._skip(self.line[0])

        return lexems, errors
```

main.py
```python
import re
import sys

from calc_lexer import Lexer
from self_applied_compiler.terms import EOF
from self_applied_compiler.topDawnParser import topDownParse
from self_applied_compiler.tree import TreeNode
from self_applied_compiler.compiler_main import build_calc_table

from generated_table import table

def evaluate(root):
    if root.content == 'S':
        operand1 = evaluate(root[0])
        operator, operand2 = evaluate(root[1])
        return (operand1 + operand2) if operator == '+' else (operand1 - operand2)

    if root.content == 'E2':
        if len(root) == 0:
            return '+', 0
        op1 = root[0][0].content
        value1 = evaluate(root[1])
        if op1 == '-':
            value1 *= -1
        op2, value2 = evaluate(root[2])
        print(value1, value2)
        return ('+', value1 + value2) if (op2 == '+') else ('+', value1 - value2)

    if root.content == 'T':
        factor1 = evaluate(root[0])
        operator, factor2 = evaluate(root[1])
        return (factor1 * factor2) if operator == '*' else (factor1 / factor2)

    if root.content == 'T2':
        if len(root) == 0:
            return '*', 1
        op1 = root[0][0].content
        value1 = evaluate(root[1])
        if op1 == '/':
            value1 = 1 / value1
        op2, value2 = evaluate(root[2])
        return ('*', value1 * value2) if (op2 == '*') else ('*', value1 / value2)

    if root.content == 'F':
        if len(root) == 1:
            return int(root[0].content)
        return evaluate(root[1])

Terminals = set("( ) + - * / NUM".split())
Terminals.add(EOF)

build_calc_table()

def main():
    grammar_path = sys.argv[1]
    lexer = Lexer(grammar_path)
    tokens, parsing_errors = lexer.parse()
    if parsing_errors:
        print("PARSING ERROR AT", parsing_errors[0])
        return

    parse_tree_root = topDownParse(tokens, Terminals, table)

    with open('graph.dot', 'w') as file:
        file.write('digraph {\n')
        parse_tree_root.print_graph(file)
        file.write('}')

    print('Evaluation Result:', evaluate(parse_tree_root))

if __name__ == '__main__':
    main()

```

# Тестирование
## Генератор компиляторов

Таблица для калькулятора

```python
table = {
    ("E", ")") : [], 
    ("T2", ")") : [], 
    ("E", "+") : ['S1', 'T', 'E'], 
    ("T2", "+") : [], 
    ("S1", "+") : ['+'], 
    ("S", "(") : ['T', 'E'], 
    ("T", "(") : ['F', 'T2'], 
    ("F", "(") : ['(', 'S', ')'], 
    ("S", "NUM") : ['T', 'E'], 
    ("T", "NUM") : ['F', 'T2'], 
    ("F", "NUM") : ['NUM'], 
    ("E", "-") : ['S1', 'T', 'E'], 
    ("T2", "-") : [], 
    ("S1", "-") : ['-'], 
    ("T2", "*") : ['S2', 'F', 'T2'], 
    ("S2", "*") : ['*'], 
    ("T2", "/") : ['S2', 'F', 'T2'], 
    ("S2", "/") : ['/'], 
    ("E", "EOF") : [], 
    ("T2", "EOF") : [], 
}

```

Табица для собственной грамматики

```python
table = {
    ("S", "EOF") : [], 
    ("A", "KW_OR") : [], 
    ("T", "KW_OR") : ['KW_OR', 'F', 'A', 'T'], 
    ("R", "KW_EPS") : ['F', 'A', 'T'], 
    ("A", "KW_EPS") : ['KW_EPS', 'A'], 
    ("F", "KW_EPS") : ['KW_EPS'], 
    ("A", "KW_END") : [], 
    ("T", "KW_END") : [], 
    ("S", "NONTERM") : ['K', 'S'], 
    ("R", "NONTERM") : ['F', 'A', 'T'], 
    ("A", "NONTERM") : ['NONTERM', 'A'], 
    ("K", "NONTERM") : ['L', 'ARROW', 'R', 'KW_END'], 
    ("L", "NONTERM") : ['NONTERM'], 
    ("F", "NONTERM") : ['NONTERM'], 
    ("S", "KW_AXIOM") : ['K', 'S'], 
    ("K", "KW_AXIOM") : ['L', 'ARROW', 'R', 'KW_END'], 
    ("L", "KW_AXIOM") : ['KW_AXIOM', 'NONTERM'], 
    ("R", "STR_TERM") : ['F', 'A', 'T'], 
    ("A", "STR_TERM") : ['STR_TERM', 'A'], 
    ("F", "STR_TERM") : ['STR_TERM'], 
}

```

## Калькулятор

Тестовый пример:
```python
(21 + 3) * 3 - 17
```

Вывод программы:
```python
55
```

# Вывод
Эта лабораторная работа оказалась неожиданно объемной по коду, пришлось изучить множество алгоритмов для
корректной реализации всех частей, и вообще без полного теоретического понимания происходящего
эту лаб. работу выполнить невозможно. При этом я считаю, что я освоил все методы реализации таких
самоприменимых компиляторов, и, что самое важное, понял суть организации процесса.
Эта лаб. работа - последняя для меня в этом курсе, который оказался интересным и разнообразным,
по-своему сложным, но при этом очень полезным для моей специальности.