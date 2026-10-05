#include <stdio.h>



int fib(int n){

	static int bufor_fib[100] = {0};
	
	bufor_fib[0] = 0;
	bufor_fib[1] = bufor_fib[2] = 1;
	
	if(bufor_fib[n] != 0){
		return bufor_fib[n];
	}
	
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	bufor_fib[n] = fib(n-1) + fib(n-2);
	return bufor_fib[n];
	
}

int main(void){
	
	int i;
	
	printf("%d\n",fib(40));
	
	/*
	for(i = 0 ; i < 50 ; i++){
		printf("fib %d: %d\n",i,bufor_fib[i]);
	}
	*/
	
	return 0;
}
