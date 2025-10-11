
#include <stdio.h>

char input = ' ';

int main(void){
	
	while(input != 'Q'){
		
		scanf(" %c",&input); /* the space before %c is IMPORTANT. */
		
		printf("%d\n",input);
		
	}
	
	return 0;
}
