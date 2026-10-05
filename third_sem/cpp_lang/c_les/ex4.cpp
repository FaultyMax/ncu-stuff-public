#include <iostream>

using namespace std;

int binary_pos_check(int num1, int num2);

int main(){

  int a = 26, b = 18;

  int c = binary_pos_check(a,b);

  cout << c << endl;

  return 0;
}

int binary_pos_check(int num1, int num2){

  int result = 0;

  for( int i = 31 ; i >= 0 ; i-- ){
    //cout << ((num1 >> i) & 1) << " " << ((num2 >> i) & 1) << endl;
    if( ((num1 >> i) & 1) == 1 and ((num2 >> i) & 1) == 1 ){
      //cout << "na pozycji " << i << "bit jest ustawiony na 1!" << endl;
      result++;
    }
  
  }

  return result;
  
}


