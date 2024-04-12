import abc
import enum
import parser_edsl as pe
import sys
from dataclasses import dataclass
from pprint import pprint
from typing import Any

class Type(enum.Enum):
    Bool = 'BOOL'
    Integer = 'INT'
    Char = 'CHAR'

