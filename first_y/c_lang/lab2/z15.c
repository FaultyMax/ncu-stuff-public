
#include <stdio.h>

int power(int a,int n){
	
	if(n==1) return a;
	
	return a * power(a,n-1);
	
}



int main(void){
	
	printf("%d\n",power(5,3));
	
	return 0;
}
