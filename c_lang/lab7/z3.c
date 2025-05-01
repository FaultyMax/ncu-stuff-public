
#include <stdio.h>
#include <stdlib.h>

enum Month {

	JAN = 1,
	FEB = 2,
	MAR = 4,
	APR = 8,
	MAY = 16,
	JUN = 32,
	JUL = 64,
	AUG = 128,
	SEP = 256,
	OCT = 512,
	NOV = 1024,
	DEC = 2048
	
};

void wypisz(int x){
	
	int i;
	
	for(i = 0 ; i < 12; i++){
		if( ((x >> i) & 1) == 1 ){
			printf("%d ",i);
		}	
	}
	
	printf("\n");
	
}

int main(void){
	
	int x = JAN+MAY+MAR;
	
	wypisz(x);
	
	return 0;
}
