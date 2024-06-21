from .terms import *
from .tree import TreeNode


def topDawnParse(u, TerminalsSet, table):
    u.append((EOF, -1, -1))
    root = TreeNode(S)
    stack = [TreeNode(EOF), root]
    result = []

    a, u = u[0], u[1:]
    while True:
        X, stack = stack[-1], stack[:-1]
        if X.content == EOF == a[0]:
            return root
        if X.content in TerminalsSet:
            if X.content == a[0]:
                X.content = a[2]
                a, u = u[0], u[1:]
            else:
                raise Exception(f'ОЖИДАЛОСЬ УВИДЕТЬ {a[0]}, А ПРИШЛО {X.content}')
        elif (X.content, a[0]) in table.keys():
            newNodes = []
            for y in table[(X.content,a[0])]:\
                newNodes.append(TreeNode(y))
            for y in newNodes[::-1]:
                X.addChild(y)
                stack.append(y)
            result.append((X, table[(X.content,a[0])]))
        else:
            print(X.content, type(X.content), a[0])
            print(table.keys())
            raise Exception(f'ТАКОГО НЕТ В ТАБЛИЦЕ: {(X.content, a[0])}')
            return
