#include <stdio.h>
#include <stdlib.h>

int kalkulator(int a, int b, int(*op)(int,int)){
	return op(a,b);
}

int add(int a, int b){
	return a+b;
}

int main(void){
	
	int x = 3;
	int y = 8;
	
	int sum = kalkulator(x,y,add);
	
	printf("Suma: %d\n", sum); 
	
	return 0;
}
