
#include <stdio.h>

int x = 74;

int main(void){
	
	if((x > -20) && (x < 30)){
		printf("malo\n");
	}
	else if((x > 50) && (x < 75)){
		printf("duzo\n");
	}
	else{
		printf("error\n");
	}
	
	return 0;
}
