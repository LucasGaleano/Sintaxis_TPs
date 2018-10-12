#ifndef PARSER_H_
#define PARSER_H_

#include "globales.h"
#include "rutinasSemanticas.h"
#include "funcionesAuxiliares.h"

void Objetivo(void);
void Programa(void);
void ListaSentencias(void);
void Sentencia(void);
void ListaIdentificadores(void);
void Identificador(REG_EXPRESION * presul);
void ListaExpresiones(void);
void Expresion(REG_EXPRESION * presul);
void Primaria(REG_EXPRESION * presul);
void OperadorAditivo(char * presul);

#endif
