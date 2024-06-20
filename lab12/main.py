import abc
import enum
from abc import ABC

import parser_edsl as pe
import sys
from dataclasses import dataclass
from pprint import pprint
from typing import Any
from pprint import pprint
import regex


class SemanticError(pe.Error):
    pass


class FunctionMainExpected(SemanticError):
    def __init__(self, pos):
        self.pos = pos

    @property
    def message(self):
        return f'Функция main ожидалась в программе'


class RepeatedFunction(SemanticError):
    def __init__(self, pos, func_name):
        self.pos = pos
        self.func_name = func_name

    @property
    def message(self):
        return f'Повторная функция {self.func_name} на {self.pos}'


class RepeatedVariable(SemanticError):
    def __init__(self, pos, varname):
        self.pos = pos
        self.varname = varname

    @property
    def message(self):
        return f'Повторная переменная {self.varname}'


class WrongFunctionType(SemanticError):
    def __init__(self, pos, functionName):
        self.pos = pos
        self.functionName = functionName

    @property
    def message(self):
        return f'Функция {self.functionName} имеет неверный тип, позиция: {self.pos}'


class WrongReturnType(SemanticError):
    def __init__(self, pos, type_expected, actual_type):
        self.pos = pos
        self.type_exp = type_expected
        self.actual_type = actual_type

    @property
    def message(self):
        return f'Неверный тип возвращаемого значения: {self.actual_type}, ожидался {self.type_exp}'


class WrongForType(SemanticError):
    def __init__(self, pos, type_):
        self.pos = pos
        self.type = type_

    @property
    def message(self):
        return f'Ожидался целый тип, получен {self.type}'


class MainFunctionIncorrect(SemanticError):
    def __init__(self, pos):
        self.pos = pos

    @property
    def message(self):
        return 'Функция Main некорректна: проверьте сигнатуру'


class MainFunctionNotFound(SemanticError):
    def __init__(self, pos):
        self.pos = pos

    @property
    def message(self):
        return f'Функция Main не найдена'

    @property
    def message(self):
        return f'Функция Main не найдена'


class UnBadType(SemanticError):
    def __init__(self, pos, op, type_):
        self.pos = pos
        self.op = op
        self.type = type_

    @property
    def message(self):
        return f'Несовместимый тип на {self.pos}: {self.op} {self.type}'


class BinBadType(SemanticError):
    def __init__(self, pos, left, op, right):
        self.pos = pos
        self.left = left
        self.op = op
        self.right = right

    @property
    def message(self):
        return f'Несовместимые типы: {self.left} {self.op} {self.right}'


class NotBoolCondition(SemanticError):
    def __init__(self, pos, type_):
        self.pos = pos
        self.type = type_

    @property
    def message(self):
        return f'Условие имеет тип {self.type} вместо логического'


class NotIntFor(SemanticError):
    def __init__(self, pos, type_):
        self.pos = pos
        self.type = type_

    @property
    def message(self):
        return f'Ожидался тип Int или Char, получен {self.type}'

    @staticmethod
    def check(type_, pos):
        if type_ not in (Type.Integer, Type.Char):
            raise NotIntFor(pos, type_)


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
    array_dim: int


@dataclass
class Ident:
    varname: str


class Expression(abc.ABC):
    @abc.abstractmethod
    def check(self, variables):
        pass


@dataclass
class DataExpression(Expression):
    term1: str
    term2: str


@dataclass
class UnOpExpr(Expression):
    op: str
    op_coord: pe.Position
    expr: Expression

    @staticmethod
    def create(operation):
        @pe.ExAction
        def action(attrs, coords, res_coords):
            expr_, = attrs
            op_coord, expr_coord = coords
            return UnOpExpr(operation, op_coord.start, expr_)

        return action

    def check(self, vars):
        self.expr.check(vars)
        if self.op == '-' and self.expr.type not in [Type.Char, Type.Integer]:
            raise UnBadType(self.op_coord, self.op, self.expr.type)
        if self.op == '!' and self.expr.type != Type.Bool:
            raise UnBadType(self.op_coord, self.op, self.expr.type)
        self.type = self.expr.type


@dataclass
class BinOpExpr(Expression):
    left: Expression
    op: str
    op_coord: pe.Position
    right: Expression

    @pe.ExAction
    def create(attrs, coords, res_coords):
        left_, op_, right_ = attrs
        left_coord, op_coord, right_coord = coords
        return BinOpExpr(left_, op_, op_coord.start, right_)


class Operator(abc.ABC):
    @abc.abstractmethod
    def check(self, variables):
        pass


@dataclass
class AssignOperator(Operator):
    expr_left: DataExpression
    left_coord: pe.Position
    expr_right: Expression

    @pe.ExAction
    def create(attrs, coords, res_coords):
        expr_left_, expr_right_ = attrs
        left_coord, assign_symb_coord, expr_right_coord = coords
        return AssignOperator(expr_left_, assign_symb_coord.start, expr_right_)

    def check(self, variables):
        self.expr_left.check(variables)
        self.expr_right.check(variables)

        if self.expr_left.type == FullType(Type.Integer, 0) and self.expr_right.type in (
                FullType(Type.Integer, 0), FullType(Type.Char, 0)):
            return
        if self.expr_left.type != self.expr_right.type:
            raise BinBadType(self.left_coord, self.expr_left.type, ':=', self.expr_right.type)


@dataclass
class Decl:
    ident: Ident
    ident_coord: pe.Position
    expr: Expression | None
    expr_coord: pe.Position | None

    @pe.ExAction
    def create(attrs, coords, res_coord):
        ident_, expr_ = attrs
        ident_coord, assign_symb_coord, expr_coord = coords
        return Decl(ident_, ident_coord.start, expr_, expr_coord)

    @pe.ExAction
    def create2(attrs, coords, res_coord):
        ident_, expr_ = attrs
        ident_coord = coords
        return Decl(ident_, ident_coord.start, None, None)


@dataclass
class DeclOperator(Operator):
    type: FullType
    decls: list[Decl]

    def check(self, variables):
        for decl in self.decls:
            if decl.ident.varname in variables:
                raise RepeatedVariable(decl.ident_coord, decl.ident)


def check_operators(ops: list[Operator], variables):
    for operator in ops:
        operator.check(variables)


@dataclass
class ChooseOperator(Operator):
    expr: Expression
    expr_coord: pe.Position
    operators1: list[Operator]
    operators2: list[Operator] | None

    @pe.ExAction
    def create(attrs, coords, res_coord):
        expr_, operators1_, operators2_ = attrs
        expr_coord, kw_then_coord, operators1_coord, kw_else_coord, operators2_coord, dot_coord = coords
        return ChooseOperator(expr_, expr_coord.start, operators1_, operators2_)

    @pe.ExAction
    def create2(attrs, coords, res_coord):
        expr_, operators1_, operators2_ = attrs
        expr_coord, kw_then_coord, operators1_coord, dot_coord = coords
        return ChooseOperator(expr_, expr_coord.start, operators1_, None)

    def check(self, variables):
        self.expr.check(variables)
        if self.expr.type != FullType(Type.Bool, 0):
            raise NotBoolCondition(self.expr_coord, self.expr.type)
        check_operators(self.operators1, variables)
        check_operators(self.operators2, variables)


@dataclass
class PredLoop(Operator):
    expr: Expression
    expr_coord: pe.Position
    ops: list[Operator]

    @pe.ExAction
    def create(attrs, coords, res_coord):
        expr_, ops_ = attrs
        expr_coord, kw_loop_coord, ops_coord, dot_coord = coords
        return PredLoop(expr_, expr_coord.start, ops_)

    def check(self, variables):
        self.expr.check(variables)
        if self.expr.type != FullType(Type.Bool, 0):
            raise NotBoolCondition(self.expr_coord, self.expr.type)
        check_operators(self.ops, variables)


@dataclass
class PostLoop(Operator):
    ops: list[Operator]
    expr_coord: pe.Position
    expr: Expression

    @pe.ExAction
    def create(attrs, coords, res_coord):
        ops_, expr_ = attrs
        kw_loop_coord, ops_coord, kw_while_coord, expr_coord, dot_coord = coords
        return PostLoop(ops_, expr_coord.start, expr_)

    def check(self, variables):
        self.expr.check(vars)
        if self.expr.type != FullType(Type.Bool, 0):
            raise NotBoolCondition(self.expr_coord, self.expr.type)



@dataclass
class ForLoop(Operator):
    exprFrom: Expression
    exprFromCoord: pe.Position
    exprTo: Expression
    exprToCoord: pe.Position
    ident: Ident
    ops: list[Operator]

    @pe.ExAction
    def create(attrs, coords, res_coord):
        expr_from_, expr_to_, ident_, ops_ = attrs
        expr_from_coord, tild_coord, expr_to_coord, kw_loop_coord, ident_coord, ops_coord, dot_coord = coords
        return ForLoop(expr_from_, expr_from_coord.start, expr_to_, expr_to_coord.start, ident_, ops_)

    def check(self, variables):
        if self.exprFrom.type not in (FullType(Type.Integer, 0), FullType(Type.Char, 0)):
            raise WrongForType(self.exprFromCoord, self.exprFrom.type)
        if self.exprTo.type not in (FullType(Type.Integer, 0), FullType(Type.Char, 0)):
            raise WrongForType(self.exprToCoord, self.exprTo.type)
        check_operators(self.ops, variables)


@dataclass
class EndFuncOperator(Operator):
    return_coord: pe.Position
    expr: Expression | None

    @pe.ExAction
    def create(attrs, coords, res_coord):
        expr_, = attrs
        return_coord, expr_coord = coords
        return EndFuncOperator(return_coord.start, expr_)

    @pe.ExAction
    def create2(attrs, coords, res_coord):
        return_coord = coords
        return EndFuncOperator(return_coord.start, None)

    def check(self, variables, func_type=None):
        if func_type is None:
            return
        else:
            if func_type == FullType(Type.Void, 0) and self.expr is not None:
                raise WrongReturnType(self.return_coord, Type.Void, func_type)
            if func_type != self.expr.type:
                raise WrongReturnType(self.return_coord, self.expr.type, func_type)
            else:
                return

@dataclass
class Parameter:
    type: FullType
    name: Ident


@dataclass
class FuncDecl:
    type: FullType
    type_coord: pe.Position
    ident: Ident
    ident_coord: pe.Position
    params: list[Parameter] | None
    ops: list[Operator]

    @pe.ExAction
    def create(attrs, coords, res_coord):
        type_, ident_, params_, ops_ = attrs
        type_coord, ident_coord, arrow_coord, params_coord, eq_coord, ops_coord, dot_coord = coords
        return FuncDecl(type_, type_coord.start, ident_, ident_coord.start, params_, ops_, )

    @pe.ExAction
    def create2(attrs, coords, res_coord):
        type_, ident_, ops_ = attrs
        type_coord, ident_coord, eq_coord, ops_coord, dot_coord = coords
        return FuncDecl(type_, type_coord.start, ident_, ident_coord.start, None, ops_, )

    def check(self):
        variables = {}
        for param in self.params:
            variables[param.name.varname] = param.type

        for operator in self.ops:
            operator.check(variables)


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

    def check(self, variables):
        pass


@dataclass
class Program:
    funcDecls: list[FuncDecl]

    def check(self):
        main_func = None
        func_names = {}
        for funcDecl in self.funcDecls:  # проверка на повторяющиеся объявления функций
            if funcDecl.ident.varname == 'Main':
                main_func = funcDecl
            if funcDecl.ident.varname in func_names:
                raise RepeatedFunction(funcDecl.ident_coord, funcDecl.ident.varname)
            func_names[funcDecl.ident.varname] = funcDecl.type.type

        if main_func:  # проверка правильно ли задана main функция
            if main_func.type.type != Type.Integer:
                raise MainFunctionIncorrect(main_func.type_coord)
            else:
                if len(main_func.params) == 1:
                    if main_func.params[0].type.type != Type.Char or main_func.params[0].type.array_dim != 2:
                        raise MainFunctionIncorrect(main_func.type_coord)
                else:
                    raise MainFunctionIncorrect(main_func.type_coord)
        else:
            raise MainFunctionNotFound(pe.Position(0, 1, 1))

        for funcDecl in self.funcDecls:
            funcDecl.check()


# лексическая структура

INTEGER_CONST = pe.Terminal('INTEGER', '[0-9]+', int, priority=7)
CHAR_LITERAL = pe.Terminal('CHAR_LITERAL', '\$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\"', str)
STRING_CONST = pe.Terminal('STRING',
                           '(\"([^\"]|%(\"[%\\]|[0-9A-Fa-f]{2}|BEL|BS|TAB|LF|VT|FF|CR))*\")',
                           str)
VARNAME = pe.Terminal('VARNAME', '[A-Za-z0-9_]+', str)


def make_keyword(image):
    return pe.Terminal(image, image, lambda name: None, priority=10)


KW_INT, KW_CHAR, KW_BOOL, KW_VOID, KW_TRUE, KW_FALSE, KW_NULL = \
    map(make_keyword, ['int', 'char', 'bool', 'void', 'true', 'false', 'null'])

KW_IF, KW_THEN, KW_ELSE, KW_RETURN, KW_LOOP, KW_WHILE = \
    map(make_keyword, ['if', 'then', 'else', 'return', 'loop', 'while'])

(NProgram, NFuncDecl, NFuncDecls, NParameters, NParameter, NOperators, NOperator,
 NDeclOperator, NFullType, NType, NExpression, NExpressions, NDataExpression, NArithmExpression, NArithmExpressions,
 NAndExpression, NCmpExpression, NFuncCallExpression, NCmpOp, NMulOp, NAddOp, NOrOp,
 NIdent, NDecls, NDecl, NTerm, NFactor, NPower, NBaseExpression) = \
    map(pe.NonTerminal,
        'Program FuncDecl FuncDecls Parameters Parameter Operators Operator '
        'DeclOperator FullType Type Expression Expressions '
        'DataExpression ArithmExpression ArithmExpressions AndExpression CmpExpression FuncCallExpression'
        ' CmpOp MulOp AddOp OrOp Ident '
        'Decls Decl Term Factor Power BaseExpression'.split())

NProgram |= NFuncDecls, Program

NFuncDecls |= NFuncDecl, lambda fnc: [fnc]
NFuncDecls |= NFuncDecls, NFuncDecl, lambda fncs, fn: fncs + [fn]

NFuncDecl |= NFullType, NIdent, '<-', NParameters, '=', NOperators, '.', FuncDecl.create
NFuncDecl |= KW_VOID, NIdent, '<-', NParameters, '=', NOperators, '.', FuncDecl.create
NFuncDecl |= NFullType, NIdent, '=', NOperators, '.', FuncDecl.create2
NFuncDecl |= KW_VOID, NIdent, '=', NOperators, '.', FuncDecl.create2

NParameters |= NParameter, lambda param: [param]
NParameters |= NParameters, ',', NParameter, lambda params, param: params + [param]

NParameter |= NFullType, NIdent, Parameter

NOperators |= NOperator, lambda op: [op]
NOperators |= NOperators, ';', NOperator, lambda ops, op: ops + [op]

NOperator |= NFullType, NDecls, DeclOperator

NDecls |= NDecl, lambda decl: [decl]
NDecls |= NDecls, ',', NDecl, lambda decls, decl: decls + [decl]

NDecl |= NIdent, Decl.create2
NDecl |= NIdent, ':=', NArithmExpression, Decl.create

NOperator |= NDataExpression, ':=', NExpression, AssignOperator.create

NOperator |= NExpression, KW_THEN, NOperators, KW_ELSE, NOperators, '.', ChooseOperator.create
NOperator |= NExpression, KW_THEN, NOperators, '.', ChooseOperator.create2

NOperator |= NIdent, "<-", NArithmExpressions, FuncCallExpression

NOperator |= KW_RETURN, NExpression, EndFuncOperator.create
NOperator |= KW_RETURN, EndFuncOperator.create2

NOperator |= NExpression, KW_LOOP, NOperators, '.', PredLoop.create
NOperator |= KW_LOOP, NOperators, KW_WHILE, NExpression, '.', PostLoop.create
NOperator |= NExpression, '~', NExpression, KW_LOOP, NIdent, NOperators, '.', ForLoop.create

NExpression |= NAndExpression
NExpression |= NAndExpression, NOrOp, NAndExpression, BinOpExpr.create


def make_op_lambda(op):
    return lambda: op


for op in ('==', '!=', '<', '>', '<=', '>='):
    NCmpOp |= op, make_op_lambda(op)

NOrOp |= "|", lambda: "|"
NOrOp |= "@", lambda: "@"

NMulOp |= "*", lambda: "*"
NMulOp |= "/", lambda: "/"
NMulOp |= "%", lambda: "%"

NAddOp |= "+", lambda: "+"
NAddOp |= "-", lambda: "-"

NAndExpression |= NCmpExpression
NAndExpression |= NCmpExpression, "&", NCmpExpression, BinOpExpr.create

NCmpExpression |= NFuncCallExpression
NCmpExpression |= NFuncCallExpression, NCmpOp, NFuncCallExpression, BinOpExpr.create

NFuncCallExpression |= NArithmExpression
NFuncCallExpression |= NIdent, "<-", NArithmExpressions, FuncCallExpression

NArithmExpressions |= NArithmExpression, lambda expr: [expr]
NArithmExpressions |= NArithmExpressions, ",", NArithmExpression, lambda exprs, expr: exprs + [expr]

NArithmExpression |= NTerm
NArithmExpression |= NArithmExpression, NAddOp, NTerm, BinOpExpr.create

NTerm |= NFactor
NTerm |= NTerm, NMulOp, NFactor, BinOpExpr.create

NFactor |= NPower
NFactor |= NPower, "^", NFactor, BinOpExpr.create

NPower |= NDataExpression
NPower |= "!", NPower, UnOpExpr.create("!")
NPower |= "-", NPower, UnOpExpr.create("-")
NPower |= NFullType, NBaseExpression, BinOpExpr.create

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

NFullType |= NType, '[][]', lambda type_: FullType(type_, 2)
NFullType |= NType, '[]', lambda type_: FullType(type_, 1)
NFullType |= NType, lambda type_: FullType(type_, 0)

NType |= KW_INT, lambda: Type.Integer
NType |= KW_CHAR, lambda: Type.Char
NType |= KW_BOOL, lambda: Type.Bool

NIdent |= "{", VARNAME, "}", Ident

parser = pe.Parser(NProgram)

# parser.print_table()
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
            tree.check()

            print('Семантических ошибок не найдено')
    except pe.Error as e:
        print(f'Ошибка {e.pos}: {e.message}')
