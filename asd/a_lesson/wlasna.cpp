
#include <iostream>
#include <string>

using namespace std;

struct node{
	
	string stored_text;
	node* ptr;
	
};

struct stack{
	
	int size;
	node* HEAD;
	
};

void push(stack* s,string value);
string pop(stack* s);
void top(stack* s);
bool empty(stack *s);

int main(){
	
	stack* stringstack =  new stack;
	stringstack->HEAD = nullptr;
	stringstack->size = 0;
	
	//cout << empty(stringstack) << endl;
	
	string input;
	
	while (input != "KONIEC"){
		
		getline(cin,input);

		push(stringstack,input);
				
	}

	pop(stringstack);

	while (empty(stringstack) == false){
		
		top(stringstack);
		pop(stringstack);
		
	}
	
	return 0;
	
}

bool empty(stack *s){

	if(s->size == 0){return true;}
	
	return false;
	
}

void push(stack *s, string value){
	
	node* next = new node;
	next->stored_text = value;
	next->ptr = s->HEAD;
	s->size++;
	s->HEAD = next;
	
}

string pop(stack* s){

	if (empty(s) == true){return 0;}
	
	string wanted_value = s->HEAD->stored_text;
	node* new_head = s->HEAD->ptr;
	delete s->HEAD;
	s->size--;
	s->HEAD = new_head;
	
	return wanted_value;
};

void top(stack *s){
	
	cout << s->HEAD->stored_text << endl;
	
}
