
#include <stdio.h>
#include <stdlib.h>

#define SWAP(t,x,y) t tmp = (x); x = (y); y = (tmp)

int main(void){
	
	int a = 23;
	int b = 11;
	
	printf("Przed SWAP: %d %d\n",a,b);
	
	SWAP(int,a,b);
	
	printf("Po SWAP: %d %d\n",a,b);
	
	return 0;
}
