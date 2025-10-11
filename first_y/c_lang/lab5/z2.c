
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	int i,temp,max;

	int n = atoi(argv[1]);
	
	if(n < 1){
		return 0;
	}
	
	scanf("%d",&max);
	
	for(i = 0 ; i < n-1 ; i++){
		scanf("%d",&temp);
		
		if(temp > max){
			max = temp;
		}
	}
	
	printf("Największa wartość: %d\n",max);
	
	return 0;
	
}
