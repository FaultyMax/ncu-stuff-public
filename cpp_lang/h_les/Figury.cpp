
#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265359

class Figure{
	
	public:
		
		virtual float get_area() = 0;
		
		virtual int get_vertices() = 0;
		
		virtual float get_cir() = 0;
	
};

class Square : public Figure{
	
	public:
		
		float a;
		
		float get_area() {
			return a*a;
		};
	
		int get_vertices() {
			return 4;
		};
	
		float get_cir() { 
			return 4*a;
		};
	
		Square(){
			a = 1;
		};
	
		Square(int a){
			this->a = a;
		};
	
};

class Circle : public Figure{
	
	public:
		
		float r;
		
		float get_area() {
				return r*r*PI;
			};
		
		int get_vertices() {
			return 0;
		};
		
		float get_cir() { 
			return 2*PI*r;
		};
		
		Circle(){
			r = 5;
		};

		Circle(float r){
			this->r = r;
		};
		
};

class Trapezoid : public Figure{
	
	public:
		
		float a,b,c,d;
		
		float get_area() {
				float h;
				float p = get_cir();
				if(a != b){
					h = (sqrt((p-2*a)*(p-2*b)*(p-2*c)*(p-2*d))) / (2*abs(b-a)); 
					//cout << h << endl;
					return (1.0f/2.0f)*(a+b)*h;
				}
				return a*b;
			};
		
		int get_vertices() {
			return 4;
		};
		
		float get_cir() { 
			return a+b+c+d;
		};
		
		Trapezoid(){
			a = 4;
			b = a;
			c = 2;
			d = c;
		};

		Trapezoid(float a,float b,float c,float d){
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		};
		
};

int main(){
	
	Figure* arr[3];

	arr[0] = new Square(5);
	arr[1] = new Circle(5);
	arr[2] = new Trapezoid(5,10,6,6);

	for(int i = 0; i < 3; i++){
        cout << "Vertices: "<<arr[i]->get_vertices() << " Area: " << arr[i]->get_area() << endl;
    }

	/*

	Square test(5);

	cout << test.get_area() << endl;
	
	Circle test2(5);
	
	cout << test2.get_area() << endl;
	
	Trapezoid lasttest(5,10,6,6);

	cout << lasttest.get_area() << endl;
	
	*/

    for(int i = 0; i < 3; i++){
    	delete arr[i];
    }

	return 0;
}

// TODO everything
