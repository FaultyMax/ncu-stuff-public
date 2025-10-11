
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	int a;
	int b;
	
} rect;

int area(a,b){

	return a*b;
	
}

int main(void){
	
	rect new_rect;
	
	new_rect.a = 5;
	new_rect.b = 4;
	
	printf("%d\n",area(new_rect.a,new_rect.b));
	
	return 0;
}
