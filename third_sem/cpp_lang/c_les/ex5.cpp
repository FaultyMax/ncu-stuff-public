#include <iostream>

using namespace std;

void binary_change(int& num);

int main(){

  int a = 31;

  binary_change(a);

  cout << a << endl;

  return 0;
}

void binary_change(int& num){

  for( int i = 31 ; i >= 0 ; i-- ){
    if( i % 2 == 0 ){
        num = num & ~( 1 << i );
    }
  
  }
  
}

//0011111 -- 31
//0001010 -- 10

