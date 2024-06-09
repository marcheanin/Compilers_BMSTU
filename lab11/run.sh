#!/bin/bash
lex lexer.l
yacc -d -Wcounterexamples parser.y
gcc -o calc *.c
rm -f lex.yy.c y.tab.?
./calc < input.txt
