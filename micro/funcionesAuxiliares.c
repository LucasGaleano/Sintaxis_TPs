#ifndef FUN_AUX
#define FUN_AUX

#include<stdio.h>
#include<string.h>
#define CANT_ELEM 50

int buscar(char*);
void agregar(char* variable, int valor);
void imprimirTabla();
int existe(char* variable);


typedef struct{
  char* variable;
  int valor;
}registro;

typedef struct{
  registro registro[CANT_ELEM];
  int cantElementos;
}ts;


ts tabla_simbolo;



int buscar(char* variable){
  for(int i=0;i<tabla_simbolo.cantElementos;i++){
    printf("%s",tabla_simbolo.registro[i].variable);
    if(strcmp(tabla_simbolo.registro[i].variable,variable)==0)
      return tabla_simbolo.registro[i].valor;
  }
  return 0;
}

void agregar(char* variable, int valor){
  if(!existe(variable)){
    tabla_simbolo.registro[tabla_simbolo.cantElementos].variable = strdup(variable);
    tabla_simbolo.registro[tabla_simbolo.cantElementos].valor = valor;
    tabla_simbolo.cantElementos += 1;
  }
}

void imprimirTabla(){
  printf("\n\ntabla de simbolos\n");
  for(int i=0;i<tabla_simbolo.cantElementos;i++){
    printf("%s\n",tabla_simbolo.registro[i].variable);
  }
}

int existe(char* variable){
  for(int i=0;i<tabla_simbolo.cantElementos;i++){
    if(strcmp(tabla_simbolo.registro[i].variable,variable)==0)
      return 1;
  }
  return 0;
}


#endif
