#include <stdio.h>

int main( int args , char * argv[]){
	
	if( !automata(argv[1]) ){
		printf("lenguaje aceptado\n");
		return 0;
	}
	printf("lenguaje incorrecto\n");
		
	return 0;
}  

int automata(char * cadena)
{
	 
	int transicion[4][2]={{2,1},{3,1},{3,1},{3,3}};
	
	int estado = 0;
	
	while(*cadena!='\0' && estado!=3){
	
		if(simbolo(*cadena++)==-1){
			estado=3;
			break;
		}
			
		estado = transicion[estado][simbolo(*cadena)];
		
	}
	
	if(estado == 3){
		return 1;
	}
	return 0;	
}


int simbolo(int c){
	
	if(c>='0' && c<='9') 
		return 1;
	if(c=='+'||c=='-')
		return 0;
	return -1; 
}
