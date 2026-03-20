
#include <iostream>

using namespace std;

struct node{
	
	int data;
	node* ptr;
	
};

void push(node** stack, int num);
void pop(node** stack);
void top(node** stack);

int main(){
	
	node* head = NULL;
	
	node** ptr = &head;
	
	push(ptr,6);
	
	cout << "W headzie jest: " << head->data << endl;
	
	push(ptr,99);
	
	cout << "W headzie jest: " << head->data << endl;
	
	pop(ptr);
	
	cout << "W headzie jest: " << head->data << endl;
	
	push(ptr,67);
	
	cout << "W headzie jest: " << head->data << endl;
	
	top(ptr);
	
	return 0;
}

void push(node** stack,int num){
	
	node *next = (node*)malloc(sizeof(node));
	next->data = num;
	next->ptr = *stack;
	*stack = next;
}

void pop(node** stack){
	
	if((stack = NULL)){return;}
	
	node *next = *stack;
	(*stack) = (*stack)->ptr;
	free(next);
}


void top(node** stack){
	
	if((stack = NULL)){return;}
	
	cout << (*stack) -> data;
	
}
