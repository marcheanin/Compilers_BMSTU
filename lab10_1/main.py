import re

from calc_lexer import Lexer
from self_applied_compiler.terms import EOF
from self_applied_compiler.topDawnParser import topDawnParse
from self_applied_compiler.tree import TreeNode
from self_applied_compiler.compiler_main import create_calc_table

from generated_table import table


def get_value(root):
    if root.content == 'S':
        val1 = get_value(root[0])
        sign, val2 = get_value(root[1])
        return (val1 + val2) if sign == '+' else (val1 - val2)

    if root.content == 'E2':
        if len(root) == 0:
            return '+', 0
        sign1 = root[0][0].content
        val1 = get_value(root[1])
        if sign1 == '-':
            val1 *= -1
        sign2, val2 = get_value(root[2])
        print(val1, val2)
        return ('+', val1 + val2) if (sign2 == '+') else ('+', val1 - val2)

    if root.content == 'T':
        val1 = get_value(root[0])
        sign, val2 = get_value(root[1])
        return (val1 * val2) if sign == '*' else (val1 / val2)

    if root.content == 'T2':
        if len(root) == 0:
            return '*', 1
        sign1 = root[0][0].content
        val1 = get_value(root[1])
        if sign1 == '/':
            val1 = 1 / val1
        sign2, val2 = get_value(root[2])
        return ('*', val1 * val2) if (sign2 == '*') else ('*', val1 / val2)

    if root.content == 'F':
        if len(root) == 1:
            return int(root[0].content)
        return get_value(root[1])


TerminalsSet = set("( ) + - * / NUM".split())
TerminalsSet.add(EOF)

create_calc_table()


def main():
    l = Lexer('test_calc.txt')
    lexems, errors = l.parse()
    if errors:
        print("ERROR AT", errors[0])
        return

    root = topDawnParse(lexems, TerminalsSet, table)

    with open('graph.dot', 'w') as f:
        f.write('digraph {\n')
        root.print_graph(f)
        f.write('}')

    print('THE ANSWER IS:', get_value(root))


if __name__ == '__main__':
    main()
