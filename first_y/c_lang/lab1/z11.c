
#include <stdio.h>

int a = 0, b = 0;

char c = ' ';

int main(void){
	
	scanf("%d %d %c",&a,&b,&c);
	
	switch(c){
	
		case '+':
			printf("%d\n",a+b);
			break;
		case '-':
			printf("%d\n",a-b);
			break;
		case '*':
			printf("%d\n",a*b);
			break;
		case '/':
			if(b == 0){
				printf("one shall not divide by zero.\n");
				break;
			}
			printf("%d\n",a/b);
			break;
		default:
			printf("something's wrong!\n");
			break;
	}
	
	return 0;
}
