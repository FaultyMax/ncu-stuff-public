
#ifndef _ZESP_

#define _ZESP_ 

class complex{

	public:
		float real;
		float imaginary;
	
		complex();
		
		complex(float re, float im);


		// +
		friend complex operator+(complex &num, complex num2);
		friend complex operator+(complex &num, float num2);
		friend complex operator+(float num, complex &num2);

		// ++
		friend complex& operator++(complex &num);
		friend complex operator++(complex &num,int);

		// -
		friend complex operator-(complex &num, complex num2);
		friend complex operator-(complex &num, float num2);
		friend complex operator-(float num, complex &num2);

		// --
		friend complex& operator--(complex &num);
		friend complex operator--(complex &num,int);

		// *

		friend complex operator*(complex &num, complex num2);
		friend complex operator*(complex &num, float num2);
		friend complex operator*(float num, complex &num2);

		// /

		friend complex operator/(complex &num, complex num2);
		friend complex operator/(complex &num, float num2);
		friend complex operator/(float num, complex &num2);
		
		//<<
		
		friend std::ostream& operator<<(std::ostream &stream, const complex &num);
		
};

#endif
