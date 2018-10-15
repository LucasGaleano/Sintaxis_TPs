
#include "funcionesAuxiliares.h"

void Match(TOKEN t)
{
  TOKEN proxT = ProximoToken();
  if ( !(t == proxT) ) {
    ErrorSintactico();
    printf("token: %s no conincide con proximo token %s\n", buscarPorNumero(t), buscarPorNumero(proxT));
  }
  flagToken = 0;
}
TOKEN ProximoToken()
{
  if ( !flagToken )
  {
    tokenActual = scanner();
    printf("proximo token: %s\n",buscarPorNumero(tokenActual));
    if ( tokenActual == ERRORLEXICO ) ErrorLexico();
    flagToken = 1;
    if ( tokenActual == ID )
    {
      Buscar(buffer, TS, &tokenActual);
    }
  }
  return tokenActual;
}
void ErrorLexico()
{
  error = 1;
  printf("Error Lexico\n");
}
void ErrorSintactico()
{
  error = 1;
  printf("Error Sintactico\n");
}
void Generar(char * co, char * a, char * b, char * c)
{
  /* Produce la salida de la instruccion para la MV por stdout */
  printf("%s %s%c%s%c%s\n", co, a, ',', b, ',', c);
}
char * Extraer(REG_EXPRESION * preg)
{
  /* Retorna la cadena del registro semantico */
  return preg->nombre;
}

int ExtraerValor(REG_EXPRESION *preg)
{
  /* Retorna la cadena del registro semantico */
  return preg->valor;
}

int Buscar(char * id, RegTS * TS, TOKEN * t)
{
  /* Determina si un identificador esta en la TS */
  int i = 0;
  while ( strcmp("$", TS[i].identifi) )
  {
    if ( !strcmp(id, TS[i].identifi) )
    {
      *t = TS[i].t;
      return 1;
    }
    i++;
  }
  return 0;
}

char* buscarPorNumero(TOKEN token){
  switch(token){
    case 0: return "inicio";
    case 1: return "fin";
    case 2: return "leer";
    case 3: return "escribir";
    case 4: return "id";
    case 5: return "numero";
    case 6: return "(";
    case 7: return ")";
    case 8: return ";";
    case 9: return ",";
    case 10: return ":=";
    case 11: return "suma";
    case 12: return "resta";
    case 13: return "fdt";
    case 14: return "error";

  }
}

void Colocar(char * id, RegTS * TS)
{
  /* Agrega un identificador a la TS */
  int i = 4;
  while ( strcmp("$", TS[i].identifi) )
    i++;
  if ( i < 999 )
  {

    strcpy(TS[i].identifi, id );
    TS[i].t = ID;
    strcpy(TS[++i].identifi, "$" );
  }
}
void Chequear(char * s)
{
  /* Si la cadena No esta en la Tabla de Simbolos la agrega, y si es el nombre de
  una variable genera la instruccion */
  TOKEN t;
  if ( !Buscar(s, TS, &t) )
  {
    Colocar(s, TS);
    Generar("Declara", s, "Entera", "");
  }
}
void Comenzar(void)
{
  /* Inicializaciones Semanticas */
}
void Terminar(void)
{
  /* Genera la instruccion para terminar la ejecucion del programa */

  Generar("Detiene", "", "", "");
  if(error)
     printf("\n[-] error en la compilacion\n");
  else
      printf("\n[+] programa compilado con exito\n");

}
void Asignar(REG_EXPRESION izq, REG_EXPRESION der)
{
  /* Genera la instruccion para la asignacion */

  Generar("Almacena", Extraer(&der), izq.nombre, "");
}
