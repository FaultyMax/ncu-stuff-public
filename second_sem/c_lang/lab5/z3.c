
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	if(argc != 4){
		printf("Nieprawidłowa ilość argumentów\n");
		return 1;
	}
	
	float a = atof(argv[1]);
	char* op = argv[2];
	float b = atof(argv[3]);
		
	switch(op[0]){
	case '+':
		printf("%.4f\n",a+b);
		break;
	case 'x':
		printf("%.4f\n",a*b);
		break;
	case '/':
		printf("%.4f\n",a/b);
		break;
	default:
		printf("Nieprawidłowy operator.\n");
		break;
	}
		
	/* printf("%f %c %f \n",a,op[0],b); */
		
	return 0;
	
}
