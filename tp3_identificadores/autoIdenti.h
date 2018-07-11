#ifndef AUTOIDENTI_H_
#define AUTOIDENTI_H_

#include <stdio.h>
#include <stdlib.h>
#define ESTADO_ERROR 2
#define TAM_PALABRA 100

int simbolo(int c);
int automataIdentificador(const char * cadena);


int caracterValido(char c);
char* leer_palabra(FILE* archivo);
void escribir_palabra( char* palabra, FILE* archivo);


#endif //AUTOIDENTI_H_
