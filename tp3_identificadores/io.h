#ifndef IO_H_
#define IO_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM_PALABRA 100

int caracterValido(char c);
char* leer_palabra(FILE* archivo);
void escribir_palabra( char* palabra, FILE* archivo);

#endif //IO_H_
