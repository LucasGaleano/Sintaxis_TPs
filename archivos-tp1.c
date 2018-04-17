#include <stdio.h>

int main(int argc, char* argv[]){


   char buffer[100]; 

   if(argc%2==0){
      printf("cantidad de archivos incorrectos\n");
      return 0;
   }
   
   while(argc!=1){
      argc = argc-2;

      FILE* archivoLeer = fopen(*++argv,"r");
      FILE* archivoEscribir = fopen(*++argv,"w");

      if(archivoLeer == NULL || archivoEscribir == NULL){
         printf("error abriendo archivos\n");
         return(-1);
      }
      printf("archivo %s copiado a %s \n",*(argv-1), *(argv));
 

      while( (fgets(buffer,20,archivoLeer)) != NULL){
          fputs(buffer,archivoEscribir);
      }
      
      fclose(archivoLeer);
      fclose(archivoEscribir);

   }
}