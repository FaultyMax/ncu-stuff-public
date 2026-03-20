
#include <iostream>

using namespace std;

struct node{
	
	int data;
	node* ptr;
	
};

struct stack{
	
	int size;
	node* HEAD;
	
};

void push(stack* s,int value);
int pop(stack* s);
void top(stack* s);
bool empty(stack *s);

int main(){
	
	stack* intstack =  new stack;
	intstack->HEAD = nullptr;
	intstack->size = 0;
	
	cout << empty(intstack) << endl;
		
	push(intstack,67);
	push(intstack,120);
	push(intstack,240);
	
	top(intstack);
	
	pop(intstack);
	
	top(intstack);
	
	return 0;
	
}

bool empty(stack *s){

	if(s->size == 0){return true;}
	
	return false;
	
}

void push(stack *s, int value){
	
	node* next = new node;
	next->data = value;
	next->ptr = s->HEAD;
	s->size++;
	s->HEAD = next;
	
}

int pop(stack* s){

	if (empty(s) == true){return 0;}
	
	int wanted_value = s->HEAD->data;
	node* new_head = s->HEAD->ptr;
	delete s->HEAD;
	s->size--;
	s->HEAD = new_head;
	
	return wanted_value;
};

void top(stack *s){
	
	cout << s->HEAD->data << endl;
	
}
