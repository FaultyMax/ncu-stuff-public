
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int x = 12;
	
	int i,j;
	
	for(i = 0 ; i < 4 ; i++){
		
		for(j = (sizeof(int)*8) - 8*(i+1) ; j < (sizeof(int)*8 - i*8) ; j++){
			/* printf("%d ",j); */
			
			printf("%d",(x >> j) & 1);
			
		}
		printf(" ");
	}

	printf("\n");
	
	return 0;
	
}
