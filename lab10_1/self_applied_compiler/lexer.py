import re
from .terms import *


class Lexer:
    def __init__(self, file_name):
        self.lines = open(file_name, 'r').readlines()
        for i, l in enumerate(self.lines):
            print(i, ":", l, end='')
        print()

    def skip_spaces(self):
        new_line = self.line.lstrip()
        self.i += len(self.line) - len(new_line)
        self.line = new_line

    def skip(self, s):
        self.i += len(s)
        self.line = self.line[len(s):]

    def parse(self):
        errors = list()
        lexems = list()

        variants = (
            (AXIOM, r'^\'axiom'),
            (EPS, r'^\'epsilon'),
            (END, r'^\'end'),
            (OR, r'^\'or'),
            (NTERM, r'^[A-Z][A-Z0-9]*'),
            (ARROW, r'^->'),
            (STR, r'^\"[^\"]*\"'),
            (COMMENT, r'^#[^\n]*')
        )

        for linenum, line in enumerate(self.lines):
            self.line = line.rstrip()
            self.i = 0
            while self.line:
                if self.line[0].isspace():
                    self.skip_spaces()
                    continue

                for typ, pattern in variants:
                    match = re.findall(pattern, self.line)
                    if match:
                        result = match[0]
                        if typ != 'comment':
                            lexems.append(
                                (typ, (linenum + 1, self.i), result.strip())
                            )

                        print((typ, (linenum + 1, self.i), result.strip()))
                        self.skip(result)
                        break
                else:
                    print('error', (linenum + 1, self.i), self.line)
                    errors.append(
                        (linenum + 1, self.i)
                    )
                    self.skip(' ')
        return lexems, errors