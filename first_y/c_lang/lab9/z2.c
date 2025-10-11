
#include <stdio.h>

typedef union{
	
	int i;
	float f;
	char c;
	
} unia;

typedef struct{
	
	int i;
	float f;
	char c;
	
} struktura;

int main(void){
	
	unia un;
	struktura st; 
	
	printf("Unia: %ld\nStruktura: %ld\n",sizeof(un),sizeof(st));
	
	return 0;
}
