#include <iostream>
#include <string>

using namespace std;

// a

struct music{

	string author;
	string title;
	int length;
	float rating;
	
};

bool check(music song);
music* compare(music* fir,music* sec);

int main(){

	// b
	
	music new_struct;
	new_struct.author = "Thomas Gwife";
	new_struct.title = "A pointer to your heart";
	new_struct.length = 167;
	new_struct.rating = 4.75;

	if(check(new_struct)){ cout << "Longer than 2:30" << endl;}

	// d

	music first; first.rating = 4.5; first.author = "..."; first.title = "?!?"; first.length = 67;
	music second; second.rating = 4.25;

	music* ptr = compare(&first,&second);

	cout << ptr->author << endl;
	cout << ptr->title << endl;
	cout << ptr->length << endl;
	cout << ptr->rating << endl;


	
	return 0;

}

// c

	
bool check(music song){

	if(song.length >= 150){ return true; }
	return false;

}

music* compare(music* fir,music* sec){
	if(fir->rating > sec->rating){ return fir; }
	else if(fir->rating == sec->rating){ cout << "Tie! Returning first." << endl; return fir; }
	return sec;
}

