
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int input = 37;
	int i;
	/* scanf("%d",&input); */
	
	/* użyj tego jeśli chcesz wypisać liczbę binarną. */
	
	for(i=(sizeof(int)*8)-1 ; i >= 0 ; i--){
		printf("%d ",(input >> i) & 1);
	}
	
	printf("\n");

	/* użyj tego jeśli chcesz działać na liczbie binarnej */
	
	for(i=0 ; i < sizeof(int)*8 ; i++){
		printf("%d ",(input >> i) & 1);
	}
	
	printf("\n");
	
	printf("%d ",(input >> 2) & 1);
	
	printf("\n");
	
	return 0;
}
