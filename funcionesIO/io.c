#include "io.h"

// int main(int argc,char* argv[]){
//
//   char* nombre_archivo_leer = argv[1];
//   char* nombre_archivo_escribir = argv[2];
//   char* palabra = NULL;
//   FILE* archivoLeer;
//   FILE* archivoEscribir;
//
//   if((archivoLeer = fopen(nombre_archivo_leer,"r")) == NULL){
//     perror("error abrir archivoa leer");
//     return 1;
//   }
//
//   if((archivoEscribir = fopen(nombre_archivo_escribir,"w")) == NULL){
//     perror("error abrir archivo a escribir");
//     return 1;
//   }
//
//   palabra = leer_palabra(archivoLeer);
//
//   while(palabra != NULL){
//     printf("%s\n",palabra);
//     escribir_palabra(archivoEscribir,palabra);
//     free(palabra);
//     palabra = leer_palabra(archivoLeer);
//   }
//
//   fclose(archivoLeer);
//   fclose(archivoEscribir);
//   return 0;
// }
//

char* leer_palabra(FILE* archivo){

  char c = 0;
  int i = 0;

  c = fgetc(archivo);
  while(!caracterValido(c) && c!=EOF)
      c = fgetc(archivo);

  if(c == EOF)
    return NULL;

  char* palabra = malloc(2);
  palabra[0] = c;

  for(i=1;i<TAM_PALABRA;i++){

    c = fgetc(archivo);

    if(!caracterValido(c) || c == EOF){
      palabra[i]='\0';
      return palabra;
    }

    palabra[i] = c;
    palabra = realloc(palabra, strlen(palabra)+1);
  }
}

int caracterValido(char c){
  if(c == ' ' || c == '\n')
    return 0;
  return 1;
}


void escribir_palabra(char* palabra, FILE* archivo){

  if(ftell(archivo)!=0) //pregunta si es el principio del archivo
    fputc(' ',archivo);
  fputs(palabra,archivo);
}
