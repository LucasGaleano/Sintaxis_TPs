%{
#include <stdio.h>
extern int yylval;
%}

numero  [0-9]+
sumar   "+"
parentesisI "("
parentesisD ")"
puntoycoma ";"
%%

{numero} {printf("numero: %s\n",yytext);yylval=atoi(yytext); return (NUM);}
{sumar} {printf("suma: %s\n",yytext); return (SUMA);}
{parentesisD} {printf("parentesis: %s\n",yytext); return (PD);}
{parentesisI} {printf("parentesis: %s\n",yytext); return (PI);}
{puntoycoma} {printf("puntoycoma: %s\n",yytext); return (PyC);}
.                       {printf("otro caracter \n");}

%%
