#include <stdio.h>
#include <stdlib.h>
#define CONSTANT 20

int main(void){
	
	int* tab = (int*)malloc(20);
	
	free(tab);
	tab = NULL;
	
	return 0;
	
}
