
#include <iostream>

using namespace std;

enum day{

  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY

};

struct calendar_page{

  int num;
  int mon;
  day dotw;

};

void wow(calendar_page c);

int main(){

  calendar_page today;
  today.num = 27;
  today.mon = 10;
  today.dotw = MONDAY;

  wow(today);

  return 0;
}

void wow(calendar_page c){
  if( c.dotw == day::SATURDAY or c.dotw == day::SUNDAY ){ cout << "weekend" << endl; }
  else{ cout << "Praca" << endl; }
}


