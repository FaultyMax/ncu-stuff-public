
#include <stdio.h>

typedef union{
	
	int i;
	float f;
	char c;
	
} unia;

int main(void){
	
	unia nowa;
	
	printf("76, 3.14, T\n");
	
	nowa.i = 76;
	
	printf("%d %f %c\n",nowa.i,nowa.f,nowa.c);
	
	nowa.f = 3.14;
	
	printf("%d %f %c\n",nowa.i,nowa.f,nowa.c);
	
	nowa.c = 'T';
	
	printf("%d %f %c\n",nowa.i,nowa.f,nowa.c);
	
	return 0;
}
