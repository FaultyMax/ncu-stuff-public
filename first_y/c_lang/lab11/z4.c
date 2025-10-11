
#include <stdio.h>
#include <stdlib.h>

#define utworz(type,nazwa,wartosc) type nazwa = wartosc

int main(void){
	
	utworz(int,zmienna,21);
	
	printf("Moja zmienna: %d\n",zmienna);
	
	return 0;
}
