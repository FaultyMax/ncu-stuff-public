
#include <stdio.h>
#include <stdlib.h>

#define COMP(a,b) a > b ? b : a

int main(void){
	
	int a = 8;
	int b = 3;
	
	printf("%d\n",COMP(a,b));
	
	return 0;
}
