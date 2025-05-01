
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomize(int a,int b){
		
	int random_num = rand() % (b-a + 1) + a;
		
	return random_num;
	
}

int main(void){
	
	int a,b;
	
	srand(time(NULL));
	
	scanf("%d %d",&a,&b);
	
	printf("%d\n",randomize(a,b));
	
	return 0;
}
