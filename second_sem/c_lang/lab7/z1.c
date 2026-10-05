
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int input = 0;
	
	scanf("%d",&input);
	
	printf("Trzeci bit : %d\n",input >> 3 & 1);
	printf("Siódmy bit : %d\n",input >> 7 & 1);
	printf("Dwunasty bit : %d\n",input >> 12 & 1);
	
	return 0;
}
