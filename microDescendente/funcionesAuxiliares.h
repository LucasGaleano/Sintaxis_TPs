#ifndef AUX_H_
#define AUX_H_

#include "globales.h"
#include "scanner.h"

void Match(TOKEN t);
TOKEN ProximoToken();
void ErrorLexico();
void ErrorSintactico();
void Generar(char * co, char * a, char * b, char * c);
char * Extraer(REG_EXPRESION * preg);
int ExtraerValor(REG_EXPRESION * preg);
int Buscar(char * id, RegTS * TS, TOKEN * t);
char* buscarPorNumero(TOKEN token);
void Colocar(char * id, RegTS * TS);
void Chequear(char * s);
void Comenzar(void);
void Terminar(void);
void Asignar(REG_EXPRESION izq, REG_EXPRESION der);

#endif
