
#include <stdio.h>

void func(int N){

	static int suma = 0;
	suma += N;
	
	printf("Dotychczasowa suma: %d\n",suma);
	
}

int main(void){
	
	int i;
	
	for(i = 0 ; i < 10 ; i++){
	
		func(i);
		
	}

	return 0;
}
