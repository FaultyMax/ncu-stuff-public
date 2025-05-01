
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int x = 0;
	
	int bit = 0;
	
	char bool = 'T';
	
	while(bool == 'T'){
		
		scanf("%d",&bit);
		
		if (bit > 31){
			printf("nieprawidłowa wartość bitu.\n");
			break;
		}
		
		if(((x >> bit) & 1) == 1){
			printf("Ponowne ustawienie bitu %d na 1.\n",bit);
			break;
		}
		
		x = x | (1 << bit);
		
	}
	
	printf("%d\n",x);


	return 0;
	
}
