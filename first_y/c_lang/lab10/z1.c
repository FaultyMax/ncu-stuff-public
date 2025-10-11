
#include <stdio.h>
#include <stdlib.h>

float minus(float a, float b){
	return a-b;
}

int main(void){
	
	float(*wsk)(float,float) = minus;
	
	printf("%f\n",wsk(5,2.5));
	
	return 0;
}
