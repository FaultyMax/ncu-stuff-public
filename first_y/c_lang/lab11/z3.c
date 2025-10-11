
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	#ifdef TEST
		printf("TEST zdefiniowany.\n");
	#endif
	
	#ifndef TEST
		printf("TEST niezdefiniowany.\n");
	#endif
	
	return 0;
	
}
