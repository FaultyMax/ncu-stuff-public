
#include <stdio.h>
#include <stdlib.h>

int isopperand(char* ent){
	
	/* 1 - jest operacją*/
	
	switch(ent[0]){
	case '+':
		return 1;
	case '-':
		return 1;
	case 'x':
		return 1;
	case '/':
		return 1;
	default:
		return 0;
	}
	
}

int operate(int a, int b, char* ent){
	
	switch(ent[0]){
	case '+':
		return a+b;
	case '-':
		return a-b;
	case 'x':
		return a*b;
	case '/':
		return a/b;
	default:
		return 0;
	}
	
}

int main(int argc, char* argv[]){
	
	int stos[100];
	int counter = 0;
	int i = 0;
	stos[0] = atoi(argv[1]);
	counter++;
	
	for( ; counter < argc ; counter++){
	
		if(isopperand(argv[i+1]) == 0){
			stos[i] = atoi(argv[i+1]);
		}
		else{
			stos[i-2] = operate(stos[i-2],stos[i-1],argv[i+1]);
			stos[i] = 0;
			stos[i-1] = 0;
			i -= 2;
		}
		i++;
	}
	
	printf("%d\n",stos[0]);
	
	return 0;
}
