
#include <stdio.h>
#include <stdlib.h>

#define TEST

#ifdef TEST
	#define LOG(x) printf("LOG: %s\n",x);
#endif

#ifndef TEST
	#define LOG(x)
#endif

int main(void){
	
	LOG("tu jest log");
	
	return 0;
}
