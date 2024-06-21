import re


class Lexer:
    def __init__(self, filepath):
        self.filepath = filepath
        self.tokens = []
        self.index = 0

    def show_tokens(self):
        for token in self.tokens:
            print(token)

    def lex_analyzer(self):
        with open(self.filepath, 'r', encoding='utf-8') as file:
            text = file.read()

        text += '\n$'

        token_patterns = [
            ('COMMENT', r'#.*$'),
            ('ARROW', r'->'),
            ('KW_END', r'\'end'),
            ('KW_AXIOM', r'\'axiom'),
            ('KW_OR', r'\'or'),
            ('KW_EPS', r'\'epsilon'),
            ('STR_TERM', r'\"[^\"\s]+\"'),
            ('NONTERM', r'[A-Z][A-Z0-9_]*'),
            ('WHITESPACE', r'[ \t\n\r]+'),
        ]

        token_pattern = r'|'.join(
            r'(?P<{}>{})'.format(name, pattern) for name, pattern in token_patterns)
        regex = re.compile(token_pattern)

        line_num = 1
        col_num = 1
        pos = 0
        syntax_error = False
        tokens = []

        while pos < len(text):
            mo = regex.match(text, pos)
            if mo is None and not syntax_error:
                syntax_error = True
                pos += 1
                col_num += 1
                continue
            elif mo is None and syntax_error:
                pos += 1
                col_num += 1
                continue
            else:
                syntax_error = False

            token_type = mo.lastgroup
            token_value = mo.group(token_type)
            token_pos = mo.start()

            if token_type == 'COMMENT':
                pass
            elif token_type == 'WHITESPACE':
                newline_count = token_value.count('\n')
                line_num += newline_count
                if newline_count != 0:
                    col_num = len(token_value) - token_value.rfind('\n')
                else:
                    col_num += len(token_value)

            else:
                tokens.append((token_type, token_value, (line_num, col_num)))

                col_num += len(token_value)
                line_num += token_value.count('\\\n')

            pos = token_pos + len(token_value)

        self.tokens = tokens

    def next_token(self):
        if not self.tokens:
            self.lex_analyzer()

        if self.index >= len(self.tokens):
            raise StopIteration("No more tokens")

        token = self.tokens[self.index]
        self.index += 1
        return token
