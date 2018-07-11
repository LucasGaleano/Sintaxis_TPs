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
*     est  C  D  error
*		0  1  2  2
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


char* leer_palabra(FILE* archivo){

  char c = 0;
  int i = 0;

  c = fgetc(archivo);
  while(!caracterValido(c) && c!=EOF)
      c = fgetc(archivo);

  if(c == EOF)
    return NULL;

  char* palabra = (char*)malloc(2);
  palabra[0] = c;

  for(i=1;i<TAM_PALABRA;i++){

    c = fgetc(archivo);

    if(!caracterValido(c) || c == EOF){
      palabra[i]='\0';
      return palabra;
    }

    palabra[i] = c;
    palabra = (char*)realloc(palabra, strlen(palabra)+1);
  }
}

int caracterValido(char c){
  if(c == ' ' || c == '\n')
    return 0;
  return 1;
}


void escribir_palabra(char* palabra, FILE* archivo){

  if(ftell(archivo)!=0) //pregunta si es el principio del archivo
    fputc(' ',archivo);
  fputs(palabra,archivo);
}

