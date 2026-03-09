
#include <iostream>

using namespace std;

struct node{
	
	string data;
	node* ptr;
	
};

void push(node** stack, string txt);
void pop(node** stack);
void top(node** stack);

int main(){
	
	node* head = NULL;
	
	node** ptr = &head;
	
	push(ptr,"txt");
	
	cout << "W headzie jest: " << head->data << endl;
	
	push(ptr,"nowy txt!");
	
	cout << "W headzie jest: " << head->data << endl;
	
	return 0;
}

void push(node** stack,string txt){
	
	node *next = (node*)malloc(sizeof(node));
	next->data = txt;
	next->ptr = *stack;
	*stack = next;
}

void pop(node** stack){
	
	if((stack = NULL)){return;}
	
	node *next = *stack;
	(*stack) = (*stack) -> ptr;
	free(next);
}


void top(node** stack){
	
	if((stack = NULL)){return;}
	
	cout << (*stack) -> data;
	
}
