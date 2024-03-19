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
    char *num_literal;
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
    yylval->num_literal = yytext;
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
        if (tag == 2) {
            printf(":\n%d\n", value.ident);
        }
        else if (tag == 1){
            printf(":\n%s\n", value.num_literal);
        }
        else if (tag == 3) {
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