%{
#include <stdio.h>
#include"funcionesAuxiliares.c"
extern int yylval;
int debug = 0;
%}

espacio (" "|\t|\n)
numero [0-9]+
identificador [a-zA-z][a-zA-z0-9]*
suma "+"
resta "-"
asignacion ":="
coma ","
PyC ";"
parenizquierdo "("
parenDerecho ")"
inicio "inicio"
fin "fin"
leer "leer"
escribir "escribir"

%%

{espacio}         ;//ignorar espacios
{suma}  {if(debug)printf("operador: %s\n",yytext);return (SUMA);}
{resta}  {if(debug)printf("operador: %s\n",yytext);return (RESTA);}
{numero} {if(debug)printf("numero: %s\n",yytext);yylval=atoi(yytext); return (NUM);}
{inicio}  {if(debug)printf("reservada: %s\n",yytext);return (INICIO);}
{leer}  {if(debug)printf("reservada: %s\n",yytext);return (LEER);}
{escribir}  {if(debug)printf("reservada: %s\n",yytext);return (ESCRIBIR);}
{fin}  {if(debug)printf("reservada: %s\n",yytext);return (FIN);}
{identificador}  {if(debug)printf("ID: %s\n",yytext);yylval=yytext[0];agregar(yytext,-1);return (ID);}
{coma} {if(debug)printf("coma: %s\n",yytext); return (COMA);}
{PyC} {if(debug)printf("PyC: %s\n",yytext); return (PyC);}
{parenizquierdo} {if(debug)printf("parenizquierdo: %s\n",yytext); return (PARENIZQUIERDO);}
{parenDerecho} {if(debug)printf("parenDerecho: %s\n",yytext); return (PARENDERECHO);}
{asignacion} {if(debug)printf("asignacion: %s\n",yytext); return (ASIGNACION);}
.           {if(debug)printf("deconocido: %s\n",yytext);}
%%
