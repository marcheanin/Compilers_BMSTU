AXIOM = 'AXIOM'
EPS = "EPS"
END = "END"
OR = "OR"
NTERM = "NTERM"
ARROW = "ARROW"
STR = "STR"
EOF = "EOF"
COMMENT = "comment"

TerminalsSet = {AXIOM, EPS, END, OR, NTERM, ARROW, STR, EOF}

S = "S"
K = "K"
L = "L"
R = "R"
A = "A"
T = "T"
F = "F"

NtermsSet = {S, K, L, R, A, T, F}

table = {
    ("A", "OR"): [],
    ("T", "OR"): ['OR', 'F', 'A', 'T'],
    ("R", "EPS"): ['F', 'A', 'T'],
    ("A", "EPS"): ['EPS', 'A'],
    ("F", "EPS"): ['EPS'],
    ("A", "END"): [],
    ("T", "END"): [],
    ("S", "NTERM"): ['K', 'S'],
    ("R", "NTERM"): ['F', 'A', 'T'],
    ("A", "NTERM"): ['NTERM', 'A'],
    ("K", "NTERM"): ['L', 'ARROW', 'R', 'END'],
    ("L", "NTERM"): ['NTERM'],
    ("F", "NTERM"): ['NTERM'],
    ("S", "AXIOM"): ['K', 'S'],
    ("K", "AXIOM"): ['L', 'ARROW', 'R', 'END'],
    ("L", "AXIOM"): ['AXIOM', 'NTERM'],
    ("R", "STR"): ['F', 'A', 'T'],
    ("A", "STR"): ['STR', 'A'],
    ("F", "STR"): ['STR'],
    ("S", "EOF"): [],
}
