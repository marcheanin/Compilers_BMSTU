import abc
import enum
import parser_edsl as pe
import sys
from dataclasses import dataclass
from pprint import pprint
from typing import Any
import regex


class Type(enum.Enum):
    Bool = 'bool'
    Integer = 'int'
    Char = 'char'
    Void = 'void'


@dataclass
class CharSequenceType:
    value: str


@dataclass
class FullType:
    type: Type


@dataclass
class Ident:
    varname: str


class Expression(abc.ABC):
    pass


@dataclass
class DataExpression(Expression):
    term1: str
    term2: str


@dataclass
class UnOpExpr(Expression):
    op: str
    expr: Expression


@dataclass
class BinOpExpr(Expression):
    left: Expression
    op: str
    right: Expression


class Operator(abc.ABC):
    pass


@dataclass
class AssignOperator(Operator):
    expr_left: DataExpression
    expr: Expression


class Decl(abc.ABC):
    pass


@dataclass
class Decl1(Decl):
    ident: Ident


@dataclass
class Decl2(Decl):
    ident: Ident
    expr: Expression


@dataclass
class DeclOperator(Operator):
    type: FullType
    decl: list[Decl]


@dataclass
class ChooseOperator1(Operator):
    expr: Expression
    operators1: list[Operator]
    operators2: list[Operator]


@dataclass
class ChooseOperator2(Operator):
    expr: Expression
    operators1: list[Operator]


@dataclass
class PredLoop(Operator):
    expr: Expression
    ops: list[Operator]


@dataclass
class PostLoop(Operator):
    ops: list[Operator]
    expr: Expression


@dataclass
class ForLoop(Operator):
    exprFrom: Expression
    exprTo: Expression
    ident: Any
    ops: list[Operator]


@dataclass
class EndFuncOperator(Operator):
    expr: Expression or None


@dataclass
class Parameter:
    type: FullType
    name: Ident


@dataclass
class FuncDecl1:
    type: FullType
    ident: Ident
    params: list[Parameter]
    ops: list[Operator]


@dataclass
class FuncDecl2:
    type: FullType
    ident: Ident
    ops: list[Operator]


@dataclass
class ArithmExpression(Expression):
    expr: Expression
    op: str
    term: str


@dataclass
class BoolExpression(Expression):
    expr1: ArithmExpression
    op: str
    expr2: Expression


@dataclass
class ConstExpr(Expression):
    value: Any
    type: Type


@dataclass
class FuncCallExpression(Expression):
    ident: Ident
    expr: list[Expression]


# лексическая структура

INTEGER_CONST = pe.Terminal('INTEGER', '[0-9]+', int, priority=7)
CHAR_LITERAL = pe.Terminal('CHAR_LITERAL', '\$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\"', str)
STRING_CONST = pe.Terminal('STRING',
                           '(\"([^\"]|%(\"[%\\]|[0-9A-Fa-f]{2}|BEL|BS|TAB|LF|VT|FF|CR))*\")|([0-7]|9|[A-Fa-f])',
                           str)
VARNAME = pe.Terminal('VARNAME', '[A-Za-z0-9_]+', str)


# OP_SYMBOL = pe.Terminal('OP_SYMBOL', '[!^*\/%+~-]==|!=|<=|>=|&|\||@', str)


def make_keyword(image):
    return pe.Terminal(image, image, lambda name: None, priority=10)


KW_INT, KW_CHAR, KW_BOOL, KW_VOID, KW_TRUE, KW_FALSE, KW_NULL = \
    map(make_keyword, ['int', 'char', 'bool', 'void', 'true', 'false', 'null'])

KW_IF, KW_THEN, KW_ELSE, KW_RETURN, KW_LOOP, KW_WHILE = \
    map(make_keyword, ['if', 'then', 'else', 'return', 'loop', 'while'])

(NProgram, NFuncDecl, NParameters, NParameter, NOperators, NOperator,
 NDeclOperator, NFullType, NType, NExpression, NExpressions, NDataExpression, NArithmExpression, NArithmExpressions,
 NAndExpression, NCmpExpression, NFuncCallExpression, NCmpOp, NMulOp, NAddOp, NOrOp,
 NIdent, NDecls, NDecl, NTerm, NFactor, NPower, NBaseExpression) = \
    map(pe.NonTerminal,
        'Program FuncDecl Parameters Parameter Operators Operator '
        'DeclOperator FullType Type Expression Expressions '
        'DataExpression ArithmExpression ArithmExpressions AndExpression CmpExpression FuncCallExpression'
        ' CmpOp MulOp AddOp OrOp Ident '
        'Decls Decl Term Factor Power BaseExpression'.split())


def make_op_lambda(op):
    return lambda: op


for op in ('==', '!=', '<', '>', '<=', '>='):
    NCmpOp |= op, make_op_lambda(op)

NProgram |= NFuncDecl, lambda st: [st]
NProgram |= NProgram, NFuncDecl, lambda fncs, fn: fncs + [fn]

NFuncDecl |= NFullType, NIdent, '<-', NParameters, '=', NOperators, '.', FuncDecl1
NFuncDecl |= KW_VOID, NIdent, '<-', NParameters, '=', NOperators, '.', FuncDecl1
NFuncDecl |= NFullType, NIdent, '=', NOperators, '.', FuncDecl2
NFuncDecl |= KW_VOID, NIdent, '=', NOperators, '.', FuncDecl2

NParameters |= NParameter, lambda param: [param]  # аналогично
NParameters |= NParameters, ',', NParameter, lambda params, param: params + [param]

NParameter |= NFullType, NIdent, Parameter

NOperators |= NOperator, lambda op: [op]
NOperators |= NOperators, ';', NOperator, lambda ops, op: ops + [op]

NOperator |= NFullType, NDecls, DeclOperator

NDecls |= NDecl, lambda decl: [decl]
NDecls |= NDecls, ',', NDecl, lambda decls, decl: decls + [decl]

NDecl |= NIdent, Decl1
NDecl |= NIdent, ':=', NExpression, Decl2

NOperator |= NDataExpression, ':=', NExpression, AssignOperator

NOperator |= NExpression, KW_THEN, NOperators, KW_ELSE, NOperators, '.', ChooseOperator1
NOperator |= NExpression, KW_THEN, NOperators, '.', ChooseOperator2

NOperator |= NIdent, "<-", NArithmExpressions, FuncCallExpression

NOperator |= KW_RETURN, NExpression, EndFuncOperator
NOperator |= KW_RETURN

NOperator |= NExpression, KW_LOOP, NOperators, '.', PredLoop
NOperator |= KW_LOOP, NOperators, KW_WHILE, NExpression, '.', PostLoop
NOperator |= NExpression, '~', NExpression, KW_LOOP, NIdent, NOperators, '.', ForLoop

NExpression |= NAndExpression
NExpression |= NAndExpression, NOrOp, NAndExpression, BinOpExpr

NOrOp |= "|", lambda: "|"
NOrOp |= "@", lambda: "@"

NMulOp |= "*", lambda: "*"
NMulOp |= "/", lambda: "/"
NMulOp |= "%", lambda: "%"

NAddOp |= "+", lambda: "+"
NAddOp |= "-", lambda: "-"

NAndExpression |= NCmpExpression
NAndExpression |= NCmpExpression, "&", NCmpExpression, BinOpExpr

NCmpExpression |= NFuncCallExpression
NCmpExpression |= NFuncCallExpression, NCmpOp, NFuncCallExpression, BinOpExpr

NFuncCallExpression |= NArithmExpression
# NFuncCallExpression |= NIdent, "<-", NArithmExpressions, FuncCallExpression

NArithmExpressions |= NArithmExpression, lambda expr: [expr]
NArithmExpressions |= NArithmExpressions, ",", NArithmExpression, lambda exprs, expr: exprs + [expr]

NArithmExpression |= NTerm
NArithmExpression |= NArithmExpression, NAddOp, NTerm, BinOpExpr

NTerm |= NFactor
NTerm |= NTerm, NMulOp, NFactor, BinOpExpr

NFactor |= NPower
NFactor |= NPower, "^", NFactor, BinOpExpr

NPower |= NDataExpression
NPower |= "!", NPower, lambda p: UnOpExpr("!", p)
NPower |= "-", NPower, lambda p: UnOpExpr("-", p)
NPower |= NFullType, NBaseExpression, lambda x, y: BinOpExpr(x, 'allocate', y)

NDataExpression |= NBaseExpression
NDataExpression |= NDataExpression, NBaseExpression, lambda x, y: BinOpExpr(x, 'at', y)
NDataExpression |= STRING_CONST, CharSequenceType

NBaseExpression |= NIdent, Ident
NBaseExpression |= KW_TRUE
NBaseExpression |= KW_FALSE
NBaseExpression |= KW_NULL
NBaseExpression |= CHAR_LITERAL
NBaseExpression |= INTEGER_CONST
NBaseExpression |= "(", NExpression, ")"

NFullType |= NType, '[][]'
NFullType |= NType, '[]'
NFullType |= NType

NType |= KW_INT, lambda: Type.Integer
NType |= KW_CHAR, lambda: Type.Char
NType |= KW_BOOL, lambda: Type.Bool

NIdent |= "{", VARNAME, "}", Ident

parser = pe.Parser(NProgram)

parser.print_table()
assert parser.is_lalr_one()

# пробельные символы
parser.add_skipped_domain('\s')
# комментарии вида ## и #( ... )#
parser.add_skipped_domain('##.*?##|#\([\s\S]*?\)#')

for filename in ["text.txt"]:
    try:
        with open(filename) as f:
            tree = parser.parse(f.read())
            pprint(tree)
    except pe.Error as e:
        print(f'Ошибка {e.pos}: {e.message}')
