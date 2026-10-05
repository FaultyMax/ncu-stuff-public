//Basic Declarations and Expressions exercise 5

#include <stdio.h>

int width = 5, height = 7;

int main(void){
	
	int Perimeter = (width*2)+(height*2);
	int Area = width*height;
	
	printf("Perimeter of the rectangle = %d inches\n",Perimeter);
	printf("Area of the rectangle = %d inches\n",Area);
	
	return 0;
	
}

/*

author's solution

#include <stdio.h> 

 
//   Variables to store the width and height of a rectangle in inches 

int width;          
int height;         

int area;           //Variable to store the area of the rectangle 
int perimeter;      //Variable to store the perimeter of the rectangle 

int main() {
    //Assigning values to height and width 
	height = 7;
	width = 5;

    //Calculating the perimeter of the rectangle 
    perimeter = 2*(height + width);
	printf("Perimeter of the rectangle = %d inches\n", perimeter);
	
    //Calculating the area of the rectangle 
	area = height * width;
	printf("Area of the rectangle = %d square inches\n", area);

    return(0);
}

*/
