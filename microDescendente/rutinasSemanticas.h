#ifndef RUTINAS_H_
#define RUTINAS_H_

#include "globales.h"
#include "funcionesAuxiliares.h"

REG_EXPRESION ProcesarCte(void);
REG_EXPRESION ProcesarId(void);
char * ProcesarOp(void);
void Leer(REG_EXPRESION in);
void Escribir(REG_EXPRESION out);
REG_EXPRESION GenInfijo(REG_EXPRESION e1, char * op, REG_EXPRESION e2);
int atoi(char* num);

#endif
