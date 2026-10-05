
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mediana(vector<int> v);

int main(){

	vector<int> ciag;

	//cout << mediana(ciag) << endl;

	int x;

	while(cin >> x){
		// robie to naiwnie i nie optymalnie
		// i gotowcami
		ciag.push_back(x);
		sort(ciag.begin(), ciag.end());
		//for (auto i : ciag){
		//	cout << i << " ";
		//}

		cout << mediana(ciag) << endl;

	}
	return 0;
}

int mediana(vector<int> v){

	int n = v.size();

	//cout << v[(n/2)-1] << endl;

	//cout << v[(n/2)] << endl;

	if(n % 2 == 0){
		return (v[(n/2)-1] + v[(n/2)])/2;
	} else { return v[n/2]; }


}

// 1,2,3,8,10  