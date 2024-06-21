import sys

from lexer import Lexer
# from calc_lexer import Lexer as CalcLexer
from parser_tree import Parser
from table_generator import TableGenerator

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


if __name__ == '__main__':
    filename = sys.argv[1]
    terminals_file = sys.argv[2]
    target_file = sys.argv[3]

    with open(terminals_file, 'r') as f:
        terminals = set(f.readline().split())

    lexer = Lexer(filename)
    lexer.lex_analyzer()
    lexer.show_tokens()
    exit(0)
    parser = Parser(lexer)

    tree = parser.top_down_parse('GRAMMAR')
    table_gen = TableGenerator()

    table_gen.generate_table(tree, terminals)
    table = table_gen.refactor_table(mapping)

    with open(target_file, 'w') as f:
        f.write('table = ' + str(table) + '\n')
        f.write('terminals = ' + str(table_gen.terminals) + '\n')
        f.write('start_symbol = \'' + str(table_gen.start_symbol) + '\'\n')
