#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>

#define ESTADO_ERROR 10

int simbolo(int c);
int itoc(char c);
int automataExpresion(const char * cadena, int *resultado);

typedef enum{
	identificador;
	constante;
	puntoYComa;
	asignacion;
	operadorSuma;
	operadorResta;
}t_lexema


#endif //SCANNER_H_
