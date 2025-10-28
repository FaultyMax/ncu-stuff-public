
#include <iostream>

using namespace std;

void binary_represent(int num);

int main(){
  /*
  int max_int =  2147483647;
  int min_int =  -2147483648;
  int test = 67;
  binary_represent(test);
  binary_represent(max_int);
  binary_represent(min_int);
  */
  int a = 918468187;

  binary_represent(a);

  cout << ( a << 10 ) << endl;
  cout << ( a >> 10 ) << endl;

  int x1 = 12, x2 = 5;

  binary_represent(x1+x2);
  binary_represent(x1-x2);
  binary_represent(x1*x2);
  binary_represent(~x1);

  return 0;
}

void binary_represent(int num){

  for(int i = 31 ; i >= 0 ; i--){

    cout << ( (num >> i) & 1 ) << " ";
  
  }
  
  cout << endl;
  
}

