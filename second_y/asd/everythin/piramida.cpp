#include <iostream>
#include <algorithm>

using namespace std;

void display(int len, int* arr){
  for(int i = 0 ; i < len ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){

  int n;

  cin >> n;

  int* tab = new int[n];

  int rows = 0;
  int tmp = n;
  do{
    rows++;
    tmp -= rows;
  }while(tmp != 0);
  
  for(int i = 0 ; i < n ; i++){
    cin >> tab[i];
  }

  int* starts = new int[rows];
  int offset = 0;
  for(int i = 0 ; i < rows ; i++){
    starts[i] = offset;
    offset += i+1;
  }

  for(int i = rows - 2; i >= 0; i--){
  
    int a = starts[i];
    int b = starts[i+1];

    for(int j = 0; j <= i ; j++){
      tab[a+j] += max(tab[b+j],tab[b+j+1]); // works??
    }
    
  }

  cout << tab[0] << endl;

  delete[] tab; delete[] starts;
  
  return 0;
}

//   3
//  1 2
// 3 5 7

//   12
//  6  9
// 3 5   7


// dla row = 3;
// zaczynam n-1 
// i2 = max: (i5+i2) (i4+i2)
// i1 = max: (i4+i1) (i3+i1)
// i0 = max: (i2+i1)

//     7
//    3 8
//   8 1 0
//  7 12 10 10

// dla row = 4;

// i5 = max: (i9+i5) (i8+i5)
// i4 = max: (i8+i4) (i7+i4)
// i3 = max: (i7+i3) (i6+i3)
// i2 = max: (i5+i2) (i4+i2)
// i1 = max: (i4+i1) (i3+i1)
// i0 = max: (i2+i1)
