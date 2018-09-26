%{
#include<stdio.h>
int yyerror(char*);
int yylex();
%}

%token NUM SUMA PI PD PyC
%%
program: statements {printf("FIN\n");}
        ;
        
statements: statement
          | statements statement
          ;

statement : expression PyC  {printf("Total: %d\n", $$);}
          | PyC
          ;

expression : expression SUMA NUM {$$ = $1 + $3; printf("expresion: %d \n", $$);}
           | NUM                       {$$ = yylval; printf("valor: %d \n", $$);}
           ;

%%
#include "lex.yy.c"
