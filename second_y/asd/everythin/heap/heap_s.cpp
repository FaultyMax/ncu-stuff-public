
#include <iostream>
#include <vector>

using namespace std;

//void heapify();

void build_heap(vector<int>& arr);

int main(){

	int n; cin >> n;

	int x;

	vector<int> heap;
	vector<int> result;

	for(int i = 0 ; i < n ; i++){

		cin >> x;

		heap.push_back(x);

	}

	for(int i = 0 ; i < n ; i++){

		build_heap(heap);

		int x = heap[0];	

		result.push_back(x);

		heap[0] = heap.back();

		heap.pop_back();

	}

	for(int i = 0 ; i < n ; i++){

		cout << result[i] << " ";

	}

	cout << endl;

	return 0;
}

void build_heap(vector<int>& arr){

	int n = arr.size();

	for(int i = 1 ; i < n ; i++){

		int j = i;

		while(j > 0){

			int parent = (j - 1) / 2;

			if(arr[j] >= arr[parent]){ break; }

			swap(arr[j], arr[parent]);

			j = parent;

		}

	}
}

// 10, 5, 20, 1, 15