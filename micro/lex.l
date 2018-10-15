%{
#include <stdio.h>
#include"funcionesAuxiliares.c"
extern int yylval;
int debug = 0;
%}

ESPACIO (" "|\t|\n)
NUMERO [0-9]+
IDENTIFICADOR [a-zA-z][a-zA-z0-9]*
SUMA "+"
RESTA "-"
ASIGNACION ":="
COMA ","
PYC ";"
PARENIZQUIERDO "("
PARENDERECHO ")"
INICIO "inicio"
FIN "fin"
LEER "leer"
ESCRIBIR "escribir"

%%
{ESPACIO}         ;//ignorar espacios
{SUMA}  {if(debug)printf("operador: %s\n",yytext);return (SUMA);}
{RESTA}  {if(debug)printf("operador: %s\n",yytext);return (RESTA);}
{NUMERO} {if(debug)printf("numero: %s\n",yytext);yylval=atoi(yytext); return (NUM);}
{INICIO}  {if(debug)printf("reservada: %s\n",yytext);return (INICIO);}
{LEER}  {if(debug)printf("reservada: %s\n",yytext);return (LEER);}
{ESCRIBIR}  {if(debug)printf("reservada: %s\n",yytext);return (ESCRIBIR);}
{FIN}  {if(debug)printf("reservada: %s\n",yytext);return (FIN);}
{IDENTIFICADOR}  {if(debug)printf("ID: %s\n",yytext);yylval=yytext[0];agregar(yytext,-1);return (ID);}
{COMA} {if(debug)printf("coma: %s\n",yytext); return (COMA);}
{PYC} {if(debug)printf("PyC: %s\n",yytext); return (PyC);}
{PARENIZQUIERDO} {if(debug)printf("parenizquierdo: %s\n",yytext); return (PARENIZQUIERDO);}
{PARENDERECHO} {if(debug)printf("parenDerecho: %s\n",yytext); return (PARENDERECHO);}
{ASIGNACION} {if(debug)printf("asignacion: %s\n",yytext); return (ASIGNACION);}
.           {if(debug)printf("deconocido: %s\n",yytext);}
%%
