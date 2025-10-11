
#include <stdio.h>

int x = 0;

int main(void){
	
	int i = 0;
	
	scanf("%d",&x);
	
	for(; i < x ; i++){
		if((i % 3 == 0) || (i % 5 == 0)){
			printf("%d\n",i);
		}
	}
	
	return 0;
}
