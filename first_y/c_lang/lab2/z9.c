
#include <stdio.h>

int fib(int n){
	
	printf("Obliczam fib(%d)\n",n);
	
	if(n <= 1) return 1;
	if(n == 2) return 1;
	
	return fib(n-1)+fib(n-2);
	
}

int main(void){
	
	printf("%d\n",fib(10));
	
	return 0;
}
