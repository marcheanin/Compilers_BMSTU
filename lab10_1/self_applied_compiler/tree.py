class Table:
    def __init__(self, nterms, terms):
        self.error = ['ERROR']
        self.table = {}
        for t in terms:
            for n in nterms:
                self.table[(n, t)] = self.error

    def add(self, n, t, seq):
        if self.table[(n, t)] == self.error:
            self.table[(n, t)] = seq
        else:
            raise Exception(f'Not ll1: Conflict on {(n, t)}')

    def to_file(self):
        with open('generated_table.py', 'w') as f:
            f.write('table = {\n')
            for key, val in self.table.items():
                print(key, val)
                if self.error == val:
                    continue
                n, t = key[0], key[1]
                n = f'"{n}"'
                t = str(t).replace('"', '')
                t = f'"{t}"'
                for i, x in enumerate(val):
                    val[i] = str(x).replace('"', '')
                f.write(f'    ({n}, {t}) : {val}, \n')
            f.write('}\n')


globalnum = 0


class TreeNode:
    def __init__(self, content):
        global globalnum
        globalnum += 1
        self.content = content
        self.children = []
        self.num = globalnum

    def addChild(self, child):
        self.children = [child] + self.children

    def __repr__(self):
        return str(self.content)

    def print_graph(self, f):
        f.write(f'{self.num} [label = "{self.num} {str(self.content)}"]\n')
        for child in self.children:
            f.write(f'{self.num} -> {child.num}\n')
        for child in self.children:
            child.print_graph(f)

    def __len__(self):
        return len(self.children)

    def __getitem__(self, i):
        return self.children[i]

    def __eq__(self, o):
        return type(self) == type(o) and self.content == o.content

    def __hash__(self):
        return len(self.content)

    def is_nterm(self):
        return 'A' <= self.content[0] <= 'Z'


class Rule:
    def __init__(self, left, is_axiom, alts):
        self.left = left
        self.is_axiom = is_axiom
        self.alts = alts

    def __str__(self):
        return f'{"[AXIOM]: " if self.is_axiom else ""}{self.left} -> {self.alts}'

    def __repr__(self):
        return str(self)


def get_rules(root):
    if len(root) == 0:
        return []
    assert len(root) == 2
    ruleNode, rulesNode = root[0], root[1]
    rule = get_rule(root[0])
    return get_rule(ruleNode) + get_rules(rulesNode)


def get_rule(root):
    assert len(root) == 4
    left, is_axiom = get_left_part(root[0])
    alts = get_right_part(root[2])
    return [Rule(left, is_axiom, list(filter(lambda x: x.content != "'epsilon", alt))) for alt in alts]


def get_left_part(root):
    if len(root) == 1:
        return root[0], False
    return root[1], True


def get_right_part(root):
    f, a, t = root[0], root[1], root[2]
    alt1 = [f[0]] + get_terms(a)
    other_alts = get_right_part2(t)
    return [alt1] + other_alts


def get_terms(root):
    if len(root) == 0:
        return []
    return [root[0]] + get_terms(root[1])


def get_right_part2(root):
    if len(root) == 0:
        return []
    f, a, t = root[1], root[2], root[3]
    alt1 = [f[0]] + get_terms(a)
    other_alts = get_right_part2(t)
    return [alt1] + other_alts
