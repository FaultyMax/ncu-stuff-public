//Basic Declarations and Expressions exercise 6

#include <stdio.h>

const double PI = 3.14159265359;

double radius;

int main(void){
	
	scanf("%lf",&radius);
	
	double perimeter = 2*PI*radius;
	double area = PI*(radius*radius);
	
	printf("The perimeter of the Circle = %lf inches\n",perimeter);
	printf("The area of the Circle = %lf inches\n",area);
	
	return 0;
}

/*

author's solution

#include <stdio.h>

int main() {
   int radius;      /* Variable to store the radius of the circle 
   float area, perimeter;    /* Variables to store the area and perimeter of the circle */ 
   radius = 6;      /* Assigning a value to the radius 

   /* Calculating the perimeter of the circle 
   perimeter = 2 * 3.14 * radius;
   printf("Perimeter of the Circle = %f inches\n", perimeter);
	
   /* Calculating the area of the circle 
   area = 3.14 * radius * radius;
   printf("Area of the Circle = %f square inches\n", area);

   return(0);
}

*/
