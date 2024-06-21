from itertools import chain
from .tree import Rule, Table
from copy import deepcopy

FIRST = {}
FOLLOW = {}
eps = 'eps$'
bucks = 'EOF'


############################################################

def get_axiom(rules):
    axioms = set(map(
        lambda x: x.left,
        filter(lambda x: x.is_axiom, rules)
    ))
    print('-> FOUND SOME AXIOMS:', axioms)
    if len(axioms) == 0:
        raise Exception('Нет входного правила')
    if len(axioms) > 1:
        raise Exception('Несколько входных правил')
    return axioms.pop()


def check_unproductive(rules):
    lefts = set(map(lambda x: x.left, rules))
    rightsall = set(chain(*[x.alts for x in rules]))
    rights = set(filter(lambda x: x.is_nterm(), rightsall))
    print(lefts)
    print(rights)
    if rights.difference(lefts) != set():
        raise Exception(f"Есть не порождающие терминалы: {rights.difference(lefts)}")


############################################################

def find_first(rules):
    global FIRST
    lefts = set(map(lambda x: x.left, rules))

    for x in lefts:
        FIRST[x] = set()

    for rule in rules:
        left, rights = rule.left, rule.alts
        FIRST[left] = FIRST[left] | get_first_seq(rights)

    while True:
        old = deepcopy(FIRST)
        for rule in rules:
            left, rights = rule.left, rule.alts
            FIRST[left] = FIRST[left] | get_first_seq(rights).difference({eps})
        if old == FIRST:
            break


def get_first_seq(rights):
    if len(rights) == 0:
        return {eps}

    a, u = rights[0], rights[1:]

    if not a.is_nterm():
        return {a}

    if eps not in FIRST[a]:
        return FIRST[a]

    return FIRST[a].difference({eps}) | get_first_seq(u)


############################################################

def find_follow(rules, axiom):
    global FOLLOW
    lefts = set(map(lambda x: x.left, rules))

    # 1
    for x in lefts:
        FOLLOW[x] = set()

    # 2
    FOLLOW[axiom] = {bucks}

    # 3
    for rule in rules:
        for i, x in enumerate(rule.alts):
            if x.is_nterm():
                v = rule.alts[i + 1:]
                f = get_first_seq(v).difference({eps})
                FOLLOW[x] = FOLLOW[x] | f
    print(FOLLOW)
    # 4
    while True:
        old = deepcopy(FOLLOW)
        for rule in rules:
            print('looking at', rule)
            X = rule.left
            for i, Y in enumerate(rule.alts):
                if Y.is_nterm():
                    print('  that has', Y, rule.alts[i + 1:], get_first_seq(rule.alts[i + 1:]))
                    if eps in get_first_seq(rule.alts[i + 1:]):
                        print(Y, '<-', get_first_seq(rule.alts[i + 1:]))
                        FOLLOW[Y] = FOLLOW[Y] | FOLLOW[X]
        if old == FOLLOW:
            break


############################################################

def build_table(rules):
    axiom = get_axiom(rules)
    check_unproductive(rules)
    find_first(rules)
    find_follow(rules, axiom)
    print('------first-----')
    for k, v in FIRST.items():
        print('   ', k, '->', v)
    print('------follow----')
    for k, v in FOLLOW.items():
        print('   ', k, '->', v)
    table = build_table2(rules)
    table.to_file()
    return table


def build_table2(rules):
    lefts = set(map(lambda x: x.left, rules))
    rightsall = set(chain(*[x.alts for x in rules]))
    rights = set(filter(lambda x: x.is_nterm(), rightsall))
    nterms = lefts | rights
    terms = rightsall.difference(rights)
    print(terms, nterms)
    table = Table(nterms, terms | {bucks})

    for rule in rules:
        X, u = rule.left, rule.alts
        # 1
        for a in get_first_seq(u).difference({eps}):
            table.add(X, a, u)
            print('adding', X, a, u)
        # 2
        if eps in get_first_seq(u):
            for b in FOLLOW[X]:
                table.add(X, b, u)

    return table





