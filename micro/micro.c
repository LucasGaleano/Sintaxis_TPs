#include<stdio.h>
#include"yacc.tab.c"
#include"lex.yy.c"


int main (int argc, char*argv[]){

  FILE *file;

  file = fopen(argv[1],"r");
  if(argc==1){
    debug = 1;
    while(yylex());
  }

  if(!file){
    printf("error abriendo el archivo\n");
    return 1;
  }

  yyin = file;
  yyparse();

  fclose(file);
}
