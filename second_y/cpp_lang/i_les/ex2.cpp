
#include <iostream>
#include <string>

template<typename T>

void print(T value){
	std::cout << value << std::endl;
}

int main(){	

	std::string World = "Hello World";
	int x = 5;

	print(World);
	print(x);

	return 0;

}