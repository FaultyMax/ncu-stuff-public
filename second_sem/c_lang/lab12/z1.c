
#include <stdio.h>
#include <stdlib.h>

float add(float a, float b){
	return a+b;
}

float subtract(float a, float b){
	return a-b;
}

float power(float a, float b){
	float wynik = a;
	int j; 
	for(j = 1; j < b ; j++ ){
		wynik *= a;
	}
	
	return wynik;
}

typedef struct{
	
	char symbol;
	float(*wsk)(float,float);
	
} op;

typedef struct{
	
	float value;
	int ilosc_op;
	op* operacje;
	
} calc;

float oblicz(calc kalkulator,char symbol, float X){
	
	int i;
	
	for(i = 0 ; i < kalkulator.ilosc_op ; i++){
	
		printf("%c\n",kalkulator.operacje[i].symbol);
		
		if(symbol == kalkulator.operacje[i].symbol){
			
			//printf("znaleziono %c\n",symbol);
			
			kalkulator.value = kalkulator.operacje[i].wsk(kalkulator.value,X);
			
			return kalkulator.value;
			
		}
		
	}
	
	printf("niepoprawny operator.\n");
	return 0;
	
}

void wypisz_calc(calc kalkulator);

int main(void){
	
	op dodaj;
	dodaj.symbol = '+';
	dodaj.wsk = add;
	
	op odjac;
	odjac.symbol = '-';
	odjac.wsk = subtract;
	
	op potega;
	
	potega.symbol = '^';
	potega.wsk = power;
	
	/*
	printf("%c\n",dodaj.symbol);
	printf("%f\n",dodaj.wsk(3.0,5.0));
	*/
	
	calc kalkulator1;
	
	kalkulator1.value = 0;
	kalkulator1.ilosc_op = 3;
	kalkulator1.operacje = (op*)malloc(sizeof(op) * kalkulator1.ilosc_op);
	
	kalkulator1.operacje[0] = dodaj;
	kalkulator1.operacje[1] = odjac;
	kalkulator1.operacje[2] = potega;
	
	/*
	kalkulator1.value = oblicz(kalkulator1,'+',5.0);
	printf("%f\n",kalkulator1.value);
	kalkulator1.value = oblicz(kalkulator1,'+',5.0);
	printf("%f\n",kalkulator1.value);
	*/
	
	
	
	return 0;
}

void wypisz_calc(calc kalkulator){

	printf("Kalkulator:\nWartość: %d\nIlość operacji: %d\nOperacje:\n",kalkulator.value,kalkulator.ilosc_op)

}
