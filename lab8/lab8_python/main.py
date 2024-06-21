import re

PROGRAM = "PROGRAM"
RULE = "RULE"
LEFT = "LEFT"
LEFT_1 = "LEFT 1"
LEFT_2 = "LEFT 2"
RIGHT = "RIGHT"
ALTERNATIVE = "ALTERNATIVE"
PART_RIGHT = "PART_RIGHT"
PART_RIGHT1 = "PART_RIGHT1"
PART_RIGHT2 = "PART_RIGHT2"
SYMB = "SYMB"

KEY_WORD_EPS = "KEY_WORD_EPS"
KEY_WORD_AXIOM = "KEY_WORD_AXIOM"
KEY_WORD_OR = "KEY_WORD_OR"
KEY_WORD_END = "KEY_WORD_END"
STR_TERM = "STR_TERM"
NONTERM = "NONTERM"
ARROW = "ARROW"
END = "END"


class Token:
    def __init__(self, token_type, value="-1", line=-1, position=-1):
        self.token_type = token_type
        self.value = value
        self.line = line
        self.position = position

    def __str__(self):
        return self.token_type + " " + str(self.value)


class Lexer:
    def __init__(self, text):
        self.text = text
        self.line = 1
        self.position = 1
        self.tokens = []
        self.rules = [
            ('END', r'\$'),
            ('SPACE', r'\s+'),
            ('KEY_WORD_EPS', r'\'epsilon'),
            ('KEY_WORD_AXIOM', r'\'axiom'),
            ('KEY_WORD_END', r'\'end'),
            ('KEY_WORD_OR', r'\'or'),
            ('KEY_WORD_END', r'\'end'),
            ('ARROW', r'->'),
            ('STR_TERM', r'\"[^\"\s]+\"'),
            ('NONTERM', r'[A-Z][A-Z0-9_]*'),
            ('COMMENT', r'#.*$')
        ]

    def tokenize(self):
        lines = self.text.splitlines()
        for line_num, line in enumerate(lines):
            self.position = 1
            self.line = line_num + 1
            while self.position < len(line) + 1:
                for rule in self.rules:
                    match = re.match(rule[1], line[self.position - 1:])
                    if match:
                        if rule[0] != 'SPACE' and rule[0] != 'COMMENT':
                            value = match.group()
                            self.tokens.append(Token(rule[0], value, self.line, self.position))
                        self.position += match.end()
                        break
                else:
                    for token in self.tokens:
                        print(token)
                    print(f'lexer error ({self.line}, {self.position})\n')
                    raise ValueError

        return iter(self.tokens)


class TreeNode:
    num = 0

    def __init__(self, content: Token):
        TreeNode.num += 1
        self.num = TreeNode.num
        self.content = content
        self.children = []

    def replace_name(self, name):
        for child in self.children:
            if child.content.token_type == STR_TERM:
                child.content.token_type = name
                break

    def add_child(self, child):
        self.children.append(child)

    def __repr__(self):
        return str(self.content)

    def print_graph(self, f):
        f.write(f'{self.num} [label = "{str(self.content.token_type)}"]\n')
        for child in self.children:
            f.write(f'{self.num} -> {child.num}\n')
        for child in self.children:
            child.print_graph(f)


class Predicter:
    def __init__(self, token_iterator):
        self.magazine = []
        self.terminals = [ARROW, KEY_WORD_END, KEY_WORD_AXIOM, NONTERM, KEY_WORD_OR, KEY_WORD_EPS, STR_TERM, END]
        self.nonterminals = [PROGRAM, RULE, LEFT, LEFT_1, LEFT_2, RIGHT, ALTERNATIVE, PART_RIGHT, PART_RIGHT2, SYMB]
        self.tokens = token_iterator
        self.table = {
            (PROGRAM, KEY_WORD_AXIOM): [RULE, PROGRAM],
            (PROGRAM, NONTERM): [RULE, PROGRAM],
            (PROGRAM, END): [],

            (RULE, KEY_WORD_AXIOM): [LEFT, ARROW, RIGHT, KEY_WORD_END],
            (RULE, NONTERM): [LEFT, ARROW, RIGHT, KEY_WORD_END],

            (LEFT, KEY_WORD_AXIOM): [LEFT_1],
            (LEFT, NONTERM): [LEFT_2],

            (LEFT_1, KEY_WORD_AXIOM): [KEY_WORD_AXIOM, NONTERM],
            (LEFT_2, NONTERM): [NONTERM],

            (RIGHT, NONTERM): [PART_RIGHT, ALTERNATIVE],
            (RIGHT, KEY_WORD_EPS): [PART_RIGHT, ALTERNATIVE],
            (RIGHT, STR_TERM): [PART_RIGHT, ALTERNATIVE],

            (ALTERNATIVE, KEY_WORD_OR): [KEY_WORD_OR, PART_RIGHT, ALTERNATIVE],
            (ALTERNATIVE, KEY_WORD_END): [],

            (PART_RIGHT, NONTERM): [SYMB, PART_RIGHT2],
            (PART_RIGHT, KEY_WORD_EPS): [KEY_WORD_EPS],
            (PART_RIGHT, STR_TERM): [SYMB, PART_RIGHT2],

            (PART_RIGHT2, NONTERM): [SYMB, PART_RIGHT2],
            (PART_RIGHT2, STR_TERM): [SYMB, PART_RIGHT2],
            (PART_RIGHT2, KEY_WORD_END): [],
            (PART_RIGHT2, KEY_WORD_OR): [],

            (SYMB, NONTERM): [NONTERM],
            (SYMB, STR_TERM): [STR_TERM],
        }

    def top_down_parse(self):
        self.magazine.append(TreeNode(Token(END)))
        root = TreeNode(Token(PROGRAM))
        self.magazine.append(root)
        a = next(self.tokens)
        result = []
        cur_x = None
        while True:
            x = self.magazine[-1]
            if x.content.token_type == END:
                break
            if x.content.token_type in self.terminals:
                if x.content.token_type == a.token_type:
                    cur_x.replace_name(a.value.replace("\"", "\\\""))
                    self.magazine.pop()
                    a = next(self.tokens)
                else:
                    raise ValueError(f"Problem with token {a.token_type}: {a.value}")

            elif (x.content.token_type, a.token_type) in self.table:
                self.magazine.pop()
                new_nodes = []
                for i in range(len(self.table[(x.content.token_type, a.token_type)])):
                    new_nodes.append(TreeNode(Token(self.table[(x.content.token_type, a.token_type)][i])))
                if len(new_nodes) == 0:
                    x.add_child(TreeNode(Token("epsilon")))
                for y in new_nodes:
                    cur_x = x
                    x.add_child(y)
                for y in new_nodes[::-1]:
                    self.magazine.append(y)
                result.append((x.content, self.table[(x.content.token_type, a.token_type)]))
            else:
                raise ValueError(f"Problem with token {a.token_type}: {a.value}")
        return root


if __name__ == "__main__":
    with open('test.txt', 'r') as f:
        text = f.read()
    lexer = Lexer(text + "$")
    try:
        iterator = lexer.tokenize()
        predicter = Predicter(iterator)
        root = predicter.top_down_parse()
        with open('graph.dot', 'w') as f:
            f.write('digraph {\n')
            root.print_graph(f)
            f.write('}')
    except ValueError as v:
        print(v)
