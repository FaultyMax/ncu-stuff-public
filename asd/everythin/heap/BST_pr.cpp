
#include <iostream>

using namespace std;

struct node{

	int val;
	node *left,*right;
	
};

node *root = nullptr;

void insertToBST(int val);
void printNode(node* nd);
void printTree(node* current);
void deleteTree(node* current);
int extractMax(node* &current);

int main(){
	
	int x;
	char input;

	while(cin >> input){

		if(input == 'e'){

			if(root != nullptr){
				x = extractMax(root);
				cout << x << " ";
			} else {
				cout << "!" << " ";
			}

		}
		else if(input == 'i'){

			cin >> x;

			insertToBST(x);

			//printTree(root);

		}
		else if(input == 'x'){
			break;
		}
	}
	
	cout << endl;

	deleteTree(root);
	root = nullptr;
	
	return 0;
}

void insertToBST(int val){
	
	node* NewNode = new node();
	
	NewNode->val = val;
	NewNode->left = nullptr;
	NewNode->right = nullptr;
	if(root == nullptr){
		root = NewNode;
		return;
	}
	
	node* current = root;
	
	while(true){
	
		if(val < current->val){
			if(current->left == nullptr){
				current->left = NewNode;
				return;
			}
			current = current->left;
		} else { 
			if(current->right == nullptr){
				current->right = NewNode;
				return;
			}
			current = current->right;
			
		}
	}
	
}

void printNode(node* nd){

	if(nd == nullptr){ return; }
	
	cout << "Value: " << nd->val;
	
	if(nd->left == nullptr){
		cout << ", LEFT: NULL";
	} else { 
		cout << ", LEFT: " << nd->left->val;
	}
	
	if(nd->right == nullptr){
		cout << ", RIGHT: NULL" << endl;
	} else { 
		cout << ", RIGHT: " << nd->right->val << endl;
	}
	
}

void printTree(node* current){
	
	if(current == nullptr){ return; }
	
	printNode(current);
	printTree(current->left);
	printTree(current->right);
	
}

void deleteTree(node* current){
	
	if(current == nullptr){ return; }
	
	deleteTree(current->left);
	deleteTree(current->right);
	delete current;
}

int extractMax(node* &current){

    if (current == nullptr){ return -1; }

    if (current->right != nullptr) {
        return extractMax(current->right);
    }

    int maxVal = current->val;
    node* temp = current;

    current = current->left; 
    
    delete temp;
    return maxVal;
}