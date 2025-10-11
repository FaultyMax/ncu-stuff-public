
#include <stdio.h>

char is_prime(int n){

	int i;

	if(n == 1) return 'N';
	
	if(n == 2 || n == 3) return 'Y';
	
	if(n % 2 == 0 || n % 3 == 0) return 'N';
	
	for(i=5 ; i*i < n ; i += 6){
		if(n % i == 0 || n % (i+2) == 0) return 'N';
	}
	
	return 'Y';
	
}

int main(void){
	
	printf("169? %c\n",is_prime(169));
	printf("71? %c\n",is_prime(71));
	printf("6829? %c\n",is_prime(6829));

	return 0;
}
