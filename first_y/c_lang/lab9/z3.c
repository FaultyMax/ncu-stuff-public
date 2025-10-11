
#include <stdio.h>
#include <string.h>

enum typ{
	
	INTEGER = 1,
	FLOAT,
	CHARACTER
	
};

typedef union{
	
	int i;
	float f;
	char c[2];
	
} unia;

typedef struct{
	
	unia u;
	enum typ e;
	
} pakiet;

void func(pakiet s){
	
	switch (s.e) {
		case INTEGER:
			printf("INTIGER: %d\n",s.u.i);
			break;
		case FLOAT:
			printf("FLOAT: %f\n",s.u.f);
			break;
		case CHARACTER:
			printf("CHARACTER: %s\n",s.u.c);
			break;
		default:
			printf("invalid type.\n");
			break;
	}
	
}

int main(void){
	
	pakiet nowy;
	
	nowy.u.i = 42;
	nowy.e = INTEGER;
	
	func(nowy);
	
	nowy.u.f = 3.141592;
	nowy.e = FLOAT;
	
	func(nowy);
	
	nowy.u.c[0] = 'Q';
	nowy.u.c[1] = '\0';
	nowy.e = CHARACTER;
	
	func(nowy);
	
	return 0;
}
