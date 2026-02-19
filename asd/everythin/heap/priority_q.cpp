#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<int>& arr, int x);

int Maximum(vector<int>& arr);

int ExtractMax(vector<int>& arr);

void Heapify(vector<int>& arr, int i);

int main(){

	vector<int> que;
	char input;
	int x;

	while(cin >> input){

		if(input == 'e'){

			if(que.empty()){
				cout << "!" << " ";
			} else {
				x = ExtractMax(que);
				cout << x << " ";
			}
			
		}
		else if(input == 'i'){

			cin >> x;

			Insert(que,x);

		}
		else if(input == 'x'){
			break;
		}
	}

	return 0;
}

void Insert(vector<int>& arr, int x){

	arr.push_back(x);

	int i = arr.size() - 1;

	while(i > 0 and arr[ (i-1)/2 ] < x){

		arr[i] = arr[ (i-1)/2 ];
		i = (i-1)/2;

	}

	arr[i] = x;

	//cout << Maximum(arr) << " ";

}

int ExtractMax(vector<int>& arr){

	if(arr.empty()){
		return -1;
	}

	int max = arr[0];

	arr[0] = arr[arr.size()-1];

	arr.pop_back();

	Heapify(arr,0);

	return max;

}

int Maximum(vector<int>& arr){

	if( !(arr.empty()) ){

		return arr[0]; 

	}

	return -1;

}

void Heapify(vector<int>& arr, int i){

	int max;

	int l = 2*i + 1;
	int p = 2*i + 2;

	if( l < (int)arr.size() and arr[l] > arr[i]  ){
		max = l;
	} else { 
		max = i;
	}
	if( p < (int)arr.size() and arr[p] > arr[max] ){
		max = p;
	}

	if( max != i ){
		swap(arr[i],arr[max]);
		Heapify(arr,max);
	}

}

/*
rodzic(i) = i/2
lewy(i) = 2i,
prawy(i) = 2i + 1
*/