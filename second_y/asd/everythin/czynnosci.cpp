#include <iostream>
#include <algorithm>

using namespace std;

struct act{
  double a;
  double b;
  int id;
};

int main(){

  int n; cin >> n;

  act* arr = new act[n];
  
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i].a ; cin >> arr[i].b;
    arr[i].id = i+1;
  }
  
  sort(arr,arr+n, [](const act &act1, const act &act2){ return (act1.a*act2.b) > (act2.a*act1.b); });

  for(int i = 0 ; i < n ; i++){
    //cout << arr[i].a << " " << arr[i].b << endl;
    cout << arr[i].id << endl;
  }
  
  //sort(points.begin(), points.end(), [](const Point &a, const Point &b) { return a.x < b.x; });

  delete[] arr;
  
  return 0;
}

// a1.a > a2.a
// 3 5 2 4 1
// a1.a > a2.b
// 3 5 4 2 1
// a1.a * a1.b > a2.a * a2.b
// 3 5 4 2 1
// a1.a * a2.b > a2.a * a1.b
// 2 4 1 5 3
