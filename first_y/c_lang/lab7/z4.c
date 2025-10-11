
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int input = 0;
	int i;
	int count = 0;
	
	scanf("%d",&input);
	
	for(i = 0 ; i < (sizeof(int)*8) ; i++){
		printf("%d",(input >> i) & 1);
		if(((input >> i) & 1) == 0){
			count++;
		}
	}
	
	printf("\nIlość bitów ustawionych na zero : %d\n",count);
	
	return 0;
}
