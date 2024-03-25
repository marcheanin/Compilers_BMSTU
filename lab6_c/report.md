% Лабораторная работа № 1.5 «Порождение лексического анализатора с помощью flex»
% 25 марта 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является изучение генератора лексических анализаторов flex.

# Индивидуальный вариант
Идентификаторы: либо последовательности латинских букв, либо непустые последовательности десятичных цифр, 
ограниченные круглыми скобками.
Числовые литералы: либо последовательности десятичных цифр, не начинающиеся с нуля, либо «0».
Операции: «()», «:», «:=».

# Реализация

```lex
%option noyywrap bison-bridge bison-locations
%{
#include <stdio.h>
#include <stdlib.h>

#define TAG_NUMERICAL_LITERAL 1
#define TAG_IDENT 2
#define TAG_OP 3

char *tag_names[] = { "END_OF_PROGRAM", "NUMERICAL_LITERAL", "IDENT", "OP" };

typedef struct Position Position;

struct Position {
    int line,pos,index;
};

void print_pos(Position *p) {
    printf("(%d,%d)",p->line,p->pos);
}

struct Fragment {
    Position starting, following;
};

typedef struct Fragment YYLTYPE;
typedef struct Fragment Fragment;

void print_frag(Fragment* f) {
    print_pos(&(f->starting));
    printf("-");
    print_pos(&(f->following));
}

union Token {
    long num_literal;
    int ident;
    char *op;
};

typedef union Token YYSTYPE;

int continued;
struct Position cur;
#define YY_USER_ACTION {             \
    int i;                           \
    if (!continued)                  \
        yylloc->starting = cur;      \
    continued = 0;                   \
    for ( i = 0; i < yyleng; i++){   \
        if ( yytext[i] == '\n'){     \
            cur.line++;              \
            cur.pos = 1;             \
        }                            \
        else                         \
            cur.pos++;               \
        cur.index++;                 \
    }                                \
    yylloc->following = cur;         \
}

long size_comment;

void init_scanner (char *program){
    continued = 0;
    cur.line = 1;
    cur.pos = 1;
    cur.index = 0;
    yy_scan_string(program);
}

void err (char *msg){
    printf ("Error");
    print_pos(&cur);
    printf(":%s\n",msg);
}

 typedef struct{
        int size;
        char** names;
    } identTable;

    void create_ident_table(identTable * t){
        t->size = 0;
        t->names = NULL;
    }

    int add_ident(identTable* table, char* name){
        for (int i = 0; i < table->size; i++){
            if (strcmp(name, table->names[i]) == 0){
                return i;
            }
        }

        table->size++;
        if (table->size == 1){
            table->names = (char**)malloc(sizeof(char*) * (table->size));
        }
        else {
            table->names = (char**)realloc(table->names, sizeof(char*) * (table->size));
        }
        table->names[table->size - 1] = (char*)malloc(sizeof(char)*strlen(name));
        strcpy(table->names[table->size - 1], name);
        return table->size-1;
    }

    identTable table;

%}

NUMERICAL_LITERAL ([1-9][0-9]*)|(0)
IDENT [a-zA-Z]+|\([0-9]+\)
OP \(\)|:=|:

%x STRING

%%
[\n\t\r ]+

{NUMERICAL_LITERAL}   {
    yylval->num_literal = atol(yytext);
    return TAG_NUMERICAL_LITERAL;
}

{OP}    {
    yylval->op = yytext;
    return TAG_OP;
}

{IDENT}               {
        yylval->ident = add_ident(&table, yytext);
        return TAG_IDENT;
}

.                     err ("ERROR");

<<EOF>>               return 0;


%%


int main(){
    int tag;
    YYSTYPE value;
    YYLTYPE coords;
    FILE *inputfile;
    long size_str;
    char *str;
    union Token token;
    inputfile = fopen("text.txt","r");
    if (inputfile == NULL) {
        fputs("File not found", stderr);
        exit(1);
    }
    fseek(inputfile, 0,SEEK_END);
    size_str = ftell(inputfile);
    rewind(inputfile);

    str=(char*)malloc(sizeof(char)*(size_str+1));
    if (str == NULL) {
        fputs("Memory error",stderr);
        exit(2);
    }
    size_t n = fread(str,sizeof(char),size_str,inputfile);
    if (n != size_str) {
        fputs ("Reading error",stderr);
        exit (3);
    }
    str[size_str] = '\0';
    fclose(inputfile);
    init_scanner(str);
    do{
        tag = yylex(&value,&coords);
        printf("%s ",tag_names[tag]);
        print_frag(&coords);
        if (tag == TAG_IDENT) {
            printf(":\n%d\n", value.ident);
        }
        else if (tag == TAG_NUMERICAL_LITERAL){
            printf(":\n%ld\n", value.num_literal);
        }
        else if (tag == TAG_OP) {
            printf(":\n%s\n", value.op);
        }
        else {
            printf(":\n");
        }
    }
    while (tag != 0);
        free(str);
    free(table.names);
    return 0;
}
```

# Тестирование

Входные данные

```
123 ()
(1233):qwe : :=
qwe (1233) ^#%
95 01
```

Вывод на `stdout`

```
NUMERICAL_LITERAL (1,1)-(1,4):
123
OP (1,5)-(1,7):
()
IDENT (2,1)-(2,7):
0
OP (2,7)-(2,8):
:
IDENT (2,8)-(2,11):
1
OP (2,12)-(2,13):
:
OP (2,14)-(2,16):
:=
IDENT (3,1)-(3,4):
1
IDENT (3,5)-(3,11):
0
Error(3,13):ERROR
Error(3,14):ERROR
Error(3,15):ERROR
NUMERICAL_LITERAL (4,1)-(4,3):
95
NUMERICAL_LITERAL (4,4)-(4,5):
0
NUMERICAL_LITERAL (4,5)-(4,6):
1
END_OF_PROGRAM (4,5)-(4,6):

```

# Вывод
В этой лабораторной работе я научился работать с генератором лексических анализаторов flex,
тем самым достигнув её цели. Для этого мне пришлось вспомнить как писать на языке C, использовать типы
и правильно выделять память. Также, пришлось применить знания полученные при разработке лексического
анализатора на основе регулярных выражений в одной из прошлых лаб. Таким образом, цель лабораторной 
работы я считаю достигнутой.