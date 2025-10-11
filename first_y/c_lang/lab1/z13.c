
#include <stdio.h>

int n = 0;

int main(void){
	
	int i = 1;
	
	scanf("%d",&n);
	
	for(; i <= n ; i++){
		
		if(n % i == 0){
			printf("%d\n",i);
		}
		
	}
	
	return 0;
}
