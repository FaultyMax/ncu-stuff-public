
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	char a;
	int b;
	char c;
	
} one;

typedef struct {
	
	char a;
	char b;
	int c;
	
} two;

int main(void){
	
	printf("c-i-c -> %ld\nc-c-i -> %ld\n",sizeof(one),sizeof(two));
	
	return 0;
	
}
