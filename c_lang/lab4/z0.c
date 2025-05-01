
#include <stdio.h>
#include <stdlib.h>

void swaap(int a,int b){

	int tmp = a;
	a = b;
	b = tmp;
	
	
}

void swaap2(int *a,int *b){

	int tmp = *a;
	*a = *b;
	*b = tmp;
	
	
}
int main(void){

	int* ptr = malloc(10*sizeof(int));

	int x = 10;
	int y = 30;
	
	int tab[5] = {0,1,2,3,4};
	
	int *ptr = tab
	
	
	
	int *ptrx = &x;
	int *ptry = &y;
	
	printf("%d %d \n",x,y);
	swaap2(ptrx,ptry);
	printf("%d %d \n",x,y);
	
	return 0;	
}
