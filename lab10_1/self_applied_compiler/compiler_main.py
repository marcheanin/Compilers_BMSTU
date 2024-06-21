from .lexer import Lexer
from .topDawnParser import topDawnParse
from .tree import get_rules
from .table_builder import build_table
from .terms import *


def create_calc_table():
    l = Lexer('self_applied_compiler/calc_grammar.txt')
    lexems, errors = l.parse()
    if errors:
        print("ERROR AT", errors[0])
        return

    root = topDawnParse(lexems, TerminalsSet, table)

    with open('graph.dot', 'w') as f:
        f.write('digraph {\n')
        root.print_graph(f)
        f.write('}')

    rules = get_rules(root)
    print('-------------')
    for x in rules:
        print(x)
    print('-------------')

    return build_table(rules)


def main():
    l = Lexer('grammar_new.txt')
    lexems, errors = l.parse()
    if errors:
        print("ERROR AT", errors[0])
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
