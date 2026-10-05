
#include <iostream>
#include "zesp.h"

complex::complex(){
			
			real = 0;
			imaginary = 0;
};

complex::complex(float re, float im){
		
			real = re;
			imaginary = im;
			
};







std::ostream& operator<<(std::ostream &stream, const complex &num){
	stream << num.real << " + " << num.imaginary << "i";
	return stream;
}

complex operator+(complex &num, complex num2){
	num.real += num2.real;
	num.imaginary += num2.imaginary;
	return num;
}

complex operator+(complex &num, float num2){
	num.real += num2;
	return num;
}

complex operator+(float num, complex &num2){
	num2.real += num;
	return num2;
}

complex& operator++(complex &num){
	num.real++;
	return num;
}

complex operator++(complex &num,int){
	complex old = num;
	num.real++;
	return old;
}

complex operator-(complex &num, complex num2){

	num.real -= num2.real;
	num.imaginary -= num2.imaginary;
	return num;
	
}

complex operator-(complex &num, float num2){
	num.real -= num2;
	return num;
}

complex operator-(float num, complex &num2){
	num2.real -= num;
	return num2;
}

complex& operator--(complex &num){
	num.real--;
	return num;
}

complex operator--(complex &num,int){
	complex old = num;
	num.real--;
	return old;
}

complex operator*(complex &num, complex num2){
	num.real = (num.real*num2.real)-(num.imaginary*num2.imaginary);
	num.imaginary = (num.imaginary*num2.real)+(num.real*num2.imaginary);
	return num;
}

complex operator*(complex &num, float num2){
	num.real *= num2;
	return num;
}

complex operator*(float num, complex &num2){
	num2.real *= num;
	return num2;
}

/*

	operatory do zaimplementownia:
	
	+, - , ++ , -- , *,  <- dwustronne
	
	/, <, <=, >, >=, ==, !=, [], <<
	

*/
