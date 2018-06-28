#include "autoExp.h"

int main( int args , char * argv[]){
	int resultado;
	if(!automataExpresion(argv[1],&resultado)){
		printf("resultado: %i\n",resultado);
		return 0;
	}
	printf("lenguaje incorrecto\n");

	return 0;
}


/*
*	estado  D  -  +  *   error
*		0	1  2  3  5   5
*		1   1  2  3  4   5
*		2   1  5  5  5   5
*		3   1  5  5  5   5
*		4   1  5  5  5   5
*		5   5  5  5  5   5
*/

int automataExpresion(const char * cadena, int *resultado){

int estado = 0;
int transicion[6][5]={{1,2,3,5,5},{1,2,3,4,5},{1,5,5,5,5},{1,5,5,5,5},{1,5,5,5,5},{5,5,5,5,5}};
int expresion = 0;
int expresionAnterior=0;
int resultadoSuma = 0;
int resultadoMultiplicacion = 1;
int signo = 1;
char caracter=0;

	while(*cadena && estado!=ESTADO_ERROR){
		caracter = *(cadena++);
		estado = transicion[estado][simbolo(caracter)];

		switch(estado){
			case 1:
				expresion = expresion * 10 + itoc(caracter);
				break;
			case 2:
				resultadoSuma += (signo*expresion * resultadoMultiplicacion);
				resultadoMultiplicacion=1;
				expresion = 0;
				signo = -1;
				break;
			case 3:
				resultadoSuma += (signo*expresion * resultadoMultiplicacion);
				resultadoMultiplicacion=1;
				expresion = 0;
				signo = 1;
				break;
			case 4:
				resultadoMultiplicacion = resultadoMultiplicacion * expresion;
				expresion = 0;
				break;
			default:
				break;

		}
		printf("expresion %i\n",expresion);
		printf("suma %i\n",resultadoSuma);
		printf("multi %i\n\n",resultadoMultiplicacion);
	}

	if(estado == ESTADO_ERROR){
		resultado = NULL;
		return -1;
	}

	*resultado = resultadoSuma + signo*expresion * resultadoMultiplicacion;

	return 0;
}


int simbolo(int c){

	if(c>='0' && c<='9')
		return 0;
	if(c=='-')
		return 1;
	if(c=='+')
		return 2;
	if(c=='*')
		return 3;

	return 4;
}

int itoc(char c){
	return c-'0';
}
