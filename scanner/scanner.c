#include "scanner.h"

int main( int args , char * argv[]){


	return 0;
}


/*	estado  c  d  ;  '' :  =  +  -
*		0	1  3  5  0  6  e  8  9
*		1   1  1  2  2  2  e  e  e
*identi	2   f  f  f  f  f  f  f  f
*		3   e  3  4  4  4  e  e  e
*conts	4   f  f  f  f  f  f  f  f
*PyC	5   f  f  f  f  f  f  f  f
*		6   e  e  e  e  e  7  e  e
*asig	7   f  f  f  f  f  f  f  f
*suma   8   f  f  f  f  f  f  f  f
*resta  9   f  f  f  f  f  f  f  f
*Error  e   e  e  e  e  e  e  e  e
*/



t_lexema scanner(char* cadena){

	char buffer[50];
	int i = 0;
	int estado = 0;
	int caracter;
	int transicion[12][8]={{1,3,5,0,6,10,8,9},{1,1,2,2,2,10,10,10},{11,11,11,11,11,11,11,11},{10,3,4,4,4,10,10,10},{11,11,11,11,11,11,11,11}
						,{11,11,11,11,11,11,11,11},{10,10,10,10,10,7,10,10},{11,11,11,11,11,11,11,11},{11,11,11,11,11,11,11,11},
						{11,11,11,11,11,11,11,11},{10,10,10,10,10,10,10,10},{11,11,11,11,11,11,11,11}};

	caracter = *(cadena++);
	while(caracter!='\0' && estado!=ESTADO_ERROR && esEstadoDeAceptacion() ){
		estado = transicion[estado][simbolo(caracter)];
		caracter = *(cadena++);
		buffer[i] = caracter;
		i++;
		if(estado == ESTADO_FINAL){}
	}

}
