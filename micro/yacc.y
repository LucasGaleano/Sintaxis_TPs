%{
#include<stdio.h>
#include"funcionesAuxiliares.c"

int yyerror(char*);
int yylex();
%}


%token SUMA RESTA NUM INICIO LEER ESCRIBIR FIN COMA PyC
%token PARENIZQUIERDO PARENDERECHO ASIGNACION
%token ID



%%
programa:INICIO sentencias FIN {printf("FIN\n");}
        ;

sentencias: sentencia
          | sentencia sentencias
          ;

sentencia : ID ASIGNACION expresion PyC   {printf("asignar %d a la variable %c\n", $3, $1); agregarValor((char*)&$1,$3);}
          | LEER  PARENIZQUIERDO identificadores PARENDERECHO PyC {printf("identificadores leidas\n");}
          | ESCRIBIR  PARENIZQUIERDO expresiones PARENDERECHO PyC {printf("expresiones escritas\n");}
          ;

identificadores : identificador
                | identificador COMA identificadores
                ;

identificador : ID
              ;

expresiones : expresion   {printf("expresion: %d\n",$1);}
            | expresion COMA expresiones {printf("expresion: %d\n",$1);}
            ;

expresion : primaria SUMA expresion  {$$ = $1 + $3;}
          | primaria RESTA expresion {$$ = $1 - $3;}
          | primaria
          ;


primaria : PARENIZQUIERDO expresion PARENDERECHO {$$ = $2;}
         | ID  {$$ = buscarValor(&$1);}
         | NUM
         ;
%%
