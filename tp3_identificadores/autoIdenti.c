#include "autoIdenti.h"


int main( int args , char * argv[]){

  char* palabra = argv[1];
	if(!automataIdentificador(palabra)){
		printf("identificador correcto: %s\n", palabra);
		return 0;
	}
	printf("identificador incorrecto: %s\n", palabra);
	return 0;
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
