
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int w,k;

	cin >> w >> k;
	
	vector<vector<int>> GraphList(w);

	for(int i = 1 ; i <= k ; i++){
	
		int a,b;
		cin >> a >> b;
		
		GraphList[a].push_back(b);
		GraphList[b].push_back(a);
		
	}

	

	return 0;
}
