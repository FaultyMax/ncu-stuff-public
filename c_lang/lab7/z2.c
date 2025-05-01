
#include <stdio.h>
#include <stdlib.h>

int bin_digits(int n){
	
	int len = 0;
	
	if (n == 0){ return 1; }
	
	if (n < 0){ return 32; }
	
	while(n > 0){
		n /= 2;
		len++;
	}
	
	return len;
	
}

int main(void){
	
	int input = 0;
	int i;
	
	scanf("%d",&input);
	/*
	printf("bin digits: %d\n",bin_digits(input));
	*/
	/* a */
	
	for(i = bin_digits(input)-1 ; i >= 0 ; i--){
	
		printf("%d",(input >> i) & 1);
		
	}
	
	printf("\n");
	
	/* b */
	
	for(i = (sizeof(int)*8)-1 ; i >= 0 ; i--){
	
		printf("%d",(input >> i) & 1);
		
	}
	
	printf("\n");
	
	return 0;
	
}
