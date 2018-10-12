#include"globales.h"
#include "parser.h"

int main(int argc, char * argv[])
{

  flagToken = 0;
  strcpy(TS[0].identifi,"inicio");
  TS[0].t =  INICIO;
  strcpy(TS[1].identifi,"fin");
  TS[1].t =  FIN;
  strcpy(TS[2].identifi,"leer");
  TS[2].t =  LEER;
  strcpy(TS[3].identifi,"escribir");
  TS[3].t =  ESCRIBIR;

  TOKEN tok;
  char nomArchi[TAMNOM];
  int l;
  if ( argc == 1 )
  {
    printf("Debe ingresar el nombre del archivo fuente (en lenguaje Micro) en la linea de comandos\n");
    return -1;
  }
  if ( argc != 2 )
  {
    printf("Numero incorrecto de argumentos\n");
    return -1;
  }
  strcpy(nomArchi, argv[1]);
  l = strlen(nomArchi);
  if ( l > TAMNOM )
  {
    printf("Nombre incorrecto del Archivo Fuente\n");
    return -1;
  }
  if ( nomArchi[l-1] != 'm' || nomArchi[l-2] != '.' )
  {
    printf("Nombre incorrecto del Archivo Fuente\n");
    return -1;
  }
  if ( (in = fopen(nomArchi, "r") ) == NULL )
  {
    printf("No se pudo abrir archivo fuente\n");
    return -1;
  }

  Objetivo();

  fclose(in);

  return 0;
}
