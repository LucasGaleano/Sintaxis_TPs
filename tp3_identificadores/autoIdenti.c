#include "autoIdenti.h"
#include "io.h"

int main( int args , char * argv[]){

  char* nombreArchivoLeer = argv[1];
  char* nombreArchivoEscribir = argv[2];
  FILE* archivoLeer;
  FILE* archivoEscribir;
  char* palabra = NULL;

  if((archivoLeer = fopen(nombreArchivoLeer,"r")) == NULL){
    perror("error abrir archivo a leer");
    return 1;
  }

  if((archivoEscribir = fopen(nombreArchivoEscribir,"w")) == NULL){
    perror("error abrir archivo a escribir");
    return 1;
  }

  palabra = leer_palabra(archivoLeer);

  while(palabra!=NULL){
    if(automataIdentificador(palabra)==0)
      escribir_palabra(palabra, archivoEscribir);
    free(palabra);
    palabra = leer_palabra(archivoLeer);
  }

  fclose(archivoLeer);
  fclose(archivoEscribir);
}


/*
*	est  C  D  error
*		0	 1  2  2
*		1  1  1  2
*		2  2  2  2
*/

int automataIdentificador(const char * cadena){

int estado = 0;
int transicion[3][3] = {{1,2,2},{1,1,2},{2,2,2}};
char caracter;

	while(*cadena && estado!=ESTADO_ERROR){
		caracter = *(cadena++);
		estado = transicion[estado][simbolo(caracter)];
	}

	if(estado == ESTADO_ERROR){
		return -1;
	}
	return 0;
}


int simbolo(int c){

  if((c >= 'A' && c <= 'z') || c == '_' || c == '$')
    return 0;
	if(c >= '0' && c <= '9')
		return 1;

	return 2;
}
