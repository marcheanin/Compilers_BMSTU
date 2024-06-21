% Лабораторная работа № 3.3 «Семантический анализ»
% 21 июня 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является получение навыков выполнения семантического анализа.

# Индивидуальный вариант
Язык L2.

Семантический анализ:
- Вызываемые функции должны быть определены в программе.
- Переменные в выражениях должны быть определены ранее.
- Область видимости переменной начинается с оператора-объявления и заканчивается 
вместе с последовательностью операторов, где она определена.
- Операции применяются к операндам допустимых типов (таблица 3).
- Операнды оператора присваивания должны быть совместимых типов.
- Типы формальных параметров должны совпадать с типами фактических параметров.

## Лексическая структура и конкретный синтаксис
Лексическая структура:
```
OrOp -> "|" | "@" .
CmpOp -> ">" | "<" | "<=" | ">=" | "==" | "!=" .
AddOp -> "+" | "-" .
MulOp -> "*" | "//" | "%" .

VARNAME -> [A-Za-z0-9_]+
STRING_CONST -> (\"([^\"]|%(\"[%\\]|[0-9A-Fa-f]{2}|BEL|BS|TAB|LF|VT|FF|CR))*\")
CHAR_LITERAL -> \$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\"
INTEGER-CONST -> [0-9]+
COMMENT -> ##.*?##|#\([\s\S]*?\)#
```

Конкретная грамматика:
```
Program -> FuncDecl
            | Program FuncDecl .

FuncDecl -> FullTypeOrVoid Ident "<-" Parameters "=" Operators "."
            | FullTypeOrVoid Ident "=" Operators "." .

FullTypeOrVoid -> FullType
                  | KW_VOID .

Parameters -> Parameter | Parameters "," Parameter .
Parameter -> FullType Ident .

Operators -> Operator | Operators ";" Operator .
Operator -> DeclOperator
            | AssignOperator
            | FuncCallOperator
            | ChooseOperator
            | PredLoopOperator
            | PostLoopOperator
            | ForLoopOperator
            | EndFuncOperator .

DeclOperator -> FullType Decls .
Decls -> Decl
        | Decls "," Decl .
Decl -> Ident
        | Ident ":=" ArithmExpression .

AssignOperator -> DataExpression ":=" Expression .

ChooseOperator -> Expression "then" Operators "else" Operators "."
                  | Expression "then" Operators "." .

PredLoopOperator -> Expression "loop" Operators "." .
ForLoopOperator -> Expression "~" Expression "loop" Ident Operators "." .
PostLoopOperator -> "loop" Operators "while" Expression "." .

EndFuncOperator -> "return" Expression
                    | "return" .

Expression -> OrExpression .
OrExpression -> AndExpression |
                AndExpression OrOp AndExpression .

AndExpression -> CmpExpression |
                 CmpExpression "&" CmpExpression .

CmpExpression -> FuncCallExpression |
                 FuncCallExpression CmpOp FuncCallExpression .

FuncCallExpression -> ArithmExpression |
                        Ident "<-" NArithmExpressions .

ArithmExpressions -> ArithmExpression |
                      ArithmExpressions "," ArithmExpression .

ArithmExpression -> Term |
                    ArithmExpression AddOp Term .

Term -> Factor |
        Term MulOp Factor .

Factor -> Power |
          Power "^" Factor .

Power -> "!" Power |
          "-" Power |
          TYPE BaseExpression |
          DataExpression .

DataExpression -> BaseExpression |
                  DataExpression BaseExpression .

BaseExpression -> STRING_CONST | CHAR_CONST | INTEGER_CONST | Ident | "(" Expression ")" .


Ident -> "{" VARNAME "}" .
FullType -> TYPE
            | TYPE "[]"
            | TYPE "[][]" .
```

# Реализация

```python
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
    def __init__(self, pos, actual_type, type_expected):
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


class UnknownVar(SemanticError):
    def __init__(self, pos, varname):
        self.pos = pos
        self.varname = varname

    @property
    def message(self):
        return f'Неизвестная переменная {self.varname}'


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
class FullType:
    type: Type
    array_dim: int


@dataclass
class CharSequenceType:
    value: str
    type: FullType


@dataclass
class Ident:
    varname: str
    varname_coord: pe.Position
    type: None

    @pe.ExAction
    def create(attrs, coords, res_coords):
        _varname, = attrs
        left_br_coord, _varname_coord, right_br_coord = coords
        return Ident(_varname, _varname_coord.start, None)

    def check(self, variables):
        try:
            self.type = variables[self.varname]
        except KeyError:
            return UnknownVar(self.varname_coord, self.varname)


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
        if self.op == '-' and self.expr.type not in [FullType(Type.Char, 0), FullType(Type.Integer, 0)]:
            raise UnBadType(self.op_coord, self.op, self.expr.type)
        if self.op == '!' and self.expr.type != FullType(Type.Bool, 0):
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

    @pe.ExAction
    def create_at(attrs, coords, res_coords):
        left_, right_ = attrs
        left_coord, right_coord = coords
        return BinOpExpr(left_, 'at', left_coord.following, right_)

    @pe.ExAction
    def create_alloc(attrs, coords, res_coords):
        left_, right_ = attrs
        left_coord, right_coord = coords
        return BinOpExpr(left_, 'alloc', left_coord.following, right_)

    def check(self, variables):
        self.left.check(variables)
        self.right.check(variables)
        self.type = None
        if self.op in ('<', '>', '<=', '>='):
            if self.left.type.array_dim == 0 and self.right.type.array_dim == 0:
                if self.left.type == FullType(Type.Integer, 0) 
                    == self.right.type == FullType(Type.Integer, 0) or \
                        self.left.type == FullType(Type.Integer, 0) 
                    == self.right.type == FullType(Type.Char, 0) or \
                        self.left.type == FullType(Type.Char, 0) 
                    == self.right.type == FullType(Type.Integer, 0) or \
                        self.left.type == FullType(Type.Char, 0) 
                    == self.right.type == FullType(Type.Char, 0):
                    self.type = FullType(Type.Bool, 0)
                else:
                    raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op in ('==', '!='):
            if self.left.type.array_dim == 0 and self.right.type.array_dim == 0:
                if self.left.type == FullType(Type.Integer, 0) == 
                    self.right.type == FullType(Type.Integer, 0) or \
                        self.left.type == FullType(Type.Integer, 0) 
                    == self.right.type == FullType(Type.Char, 0) or \
                        self.left.type == FullType(Type.Char, 0) 
                    == self.right.type == FullType(Type.Integer, 0) or \
                        self.left.type == FullType(Type.Char, 0) 
                    == self.right.type == FullType(Type.Char, 0) or \
                        self.left.type == FullType(Type.Bool, 0) 
                    == self.right.type == FullType(Type.Bool, 0):
                    self.type = FullType(Type.Bool, 0)
                else:
                    raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
            elif self.left.type.array_dim != self.right.type.array_dim:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op in ('&', '|', '@'):
            if self.left.type == FullType(Type.Bool, 0) == self.right.type == FullType(Type.Bool, 0):
                self.type = FullType(Type.Bool, 0)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op in ('^', '*', '/', '%'):
            if self.left.type == FullType(Type.Integer, 0) == self.right.type == FullType(Type.Integer, 0):
                self.type = FullType(Type.Integer, 0)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op == 'at':
            if self.left.type.array_dim > 0 and self.right.type.array_dim == 0:
                if self.right.type.type == Type.Integer or self.right.type.type == Type.Char:
                    self.type = FullType(self.left.type.type, 0)
                else:
                    raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op == '+':
            if self.left.type.array_dim == 0 and self.right.type.array_dim == 0:
                if self.left.type.type == Type.Integer and self.right.type.type == Type.Integer:
                    self.type = FullType(Type.Integer, 0)
                elif self.left.type.type == Type.Integer and self.right.type.type == Type.Char:
                    self.type = FullType(Type.Char, 0)
                elif self.left.type.type == Type.Char and self.right.type.type == Type.Integer:
                    self.type = FullType(Type.Char, 0)
                else:
                    raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
        elif self.op == '-':
            if self.left.type.array_level == 0 and self.right.type.array_level == 0:
                if self.left.type.type == Type.Integer and self.right.type.type == Type.Integer:
                    self.type = FullType(Type.Integer, 0)
                elif self.left.type.type == Type.Char and self.right.type.type == Type.Char:
                    self.type = FullType(Type.Integer, 0)
                elif self.left.type.type == Type.Char and self.right.type.type == Type.Integer:
                    self.type = FullType(Type.Char, 0)
                else:
                    raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)
            else:
                raise BinBadType(self.op_coord, self.left.type, self.op, self.right.type)

        if self.type is None:
            raise BinBadType(self.op_coord, self.left.type,
                             self.op, self.right.type)


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
            else:
                if decl.expr is not None:
                    decl.expr.check(variables)
                    if self.type == decl.expr.type:
                        variables[decl.ident.varname] = decl.expr.type
                    else:
                        raise BinBadType(decl.expr_coord, self.type, decl.expr.type)
                else:
                    variables[decl.ident.varname] = None


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
        expr_from_coord, tild_coord, expr_to_coord, \
        kw_loop_coord, ident_coord, ops_coord, dot_coord = coords
        return ForLoop(expr_from_, expr_from_coord.start, expr_to_, expr_to_coord.start, ident_, ops_)

    def check(self, variables):
        self.exprFrom.check(variables)
        self.exprTo.check(variables)
        if self.exprFrom.type not in (FullType(Type.Integer, 0), FullType(Type.Char, 0)):
            raise WrongForType(self.exprFromCoord, self.exprFrom.type)
        if self.exprTo.type not in (FullType(Type.Integer, 0), FullType(Type.Char, 0)):
            raise WrongForType(self.exprToCoord, self.exprTo.type)
        variables[self.ident.varname] = FullType(Type.Integer, 0)
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
            self.expr.check(variables)
            if func_type == FullType(Type.Void, 0) and self.expr is not None:
                raise WrongReturnType(self.return_coord, self.expr.type, Type.Void)
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
            if isinstance(operator, EndFuncOperator):
                operator.check(variables, self.type)
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
class ConstExpr(Expression):
    value: Any
    type: FullType

    def check(self, vars):
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
                    if main_func.params[0].type.type != Type.Char 
                        or main_func.params[0].type.array_dim != 2:
                        raise MainFunctionIncorrect(main_func.type_coord)
                else:
                    raise MainFunctionIncorrect(main_func.type_coord)
        else:
            raise MainFunctionNotFound(pe.Position(0, 1, 1))

        for funcDecl in self.funcDecls:
            funcDecl.check()


# лексическая структура

INTEGER_CONST = pe.Terminal('INTEGER', '[0-9]+', int, priority=7)
CHAR_LITERAL = pe.Terminal('CHAR_LITERAL', 
                           '\$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\"', str)
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
 NDeclOperator, NFullType, NType, NExpression, NExpressions, NDataExpression, 
 NArithmExpression, NArithmExpressions,
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
NPower |= NFullType, NBaseExpression, BinOpExpr.create_alloc

NDataExpression |= NBaseExpression
NDataExpression |= NDataExpression, NBaseExpression, BinOpExpr.create_at
NDataExpression |= STRING_CONST, lambda expr: ConstExpr(expr, FullType(Type.Char, 1))

NBaseExpression |= NIdent
NBaseExpression |= KW_TRUE, lambda expr: ConstExpr(expr, FullType(Type.Bool, 0))
NBaseExpression |= KW_FALSE, lambda expr: ConstExpr(expr, FullType(Type.Bool, 0))
NBaseExpression |= KW_NULL, lambda expr: ConstExpr(expr, FullType(Type.Integer, 1))
NBaseExpression |= CHAR_LITERAL, lambda expr: ConstExpr(expr, FullType(Type.Char, 0))
NBaseExpression |= INTEGER_CONST, lambda expr: ConstExpr(expr, FullType(Type.Integer, 0))
NBaseExpression |= "(", NExpression, ")"

NFullType |= NType, '[][]', lambda type_: FullType(type_, 2)
NFullType |= NType, '[]', lambda type_: FullType(type_, 1)
NFullType |= NType, lambda type_: FullType(type_, 0)

NType |= KW_INT, lambda: Type.Integer
NType |= KW_CHAR, lambda: Type.Char
NType |= KW_BOOL, lambda: Type.Bool

NIdent |= "{", VARNAME, "}", Ident.create

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

```

# Тестирование

Приведем пример одной из семантических ошибок:
## Входные данные

```
int[] {SumVectors}
    <- int[] {A}, int[] {B}
    = int {size} := 10;
    int[] {C} := {A};
    int {E} := 15;
    char[] {D} := "Hello world";
    {FuncName} <- {A}, {B}, 5 / (10 * 3);
    int {res_func} := (65 + 7) * {E} ;
    0 ~ {size} loop {i}
        {C}{i} := {A}{i} + {B}{i} . ;
    ## КОММЕНТАРИЙ ##
    #(
        многострочный комментарий
    )#
    {A}5 < 7 then {C}0 := 2
    else {C}0 := 5 . ;
    return 14 .

int {Main} <- char[][] {A} = return 0 .
```

## Вывод на `stdout`

```
Ошибка (17, 5): Неверный тип возвращаемого значения: FullType(type=<Type.Integer: 'int'>, array_dim=0), 
ожидался FullType(type=<Type.Integer: 'int'>, array_dim=1)
```

# Вывод
Это лабораторная работа оказалась одной из самых интересных для меня. Навыки написания семантических правил 
являются не менее важными, чем предыдущие этапы разбора программы. При этом освоив функционал этой 
библиотеки, дело остается за логикой и красотой написания и проектирования кода (при наличии качественно
выполненной лабы 2.2, конечно). Я считаю, что мне повезло с языком, в плане его "обычности", и теперь
я могу примерно представлять как можно реализовать семантический анализ в популярных языках,
таких как с++, java, python