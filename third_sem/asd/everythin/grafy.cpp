#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find(vector<int> arr,int x){

	for(int i : arr){
		if( i == x ) { return true ; }
	}
	return false;
}

bool dfs(int v,vector<vector<int>> GraphList);

int main(){
	
	int vertices, edges;
	
	cin >> vertices >> edges;
	
	//vector<vector<bool>> GraphMatrix(vertices, vector<bool>(vertices, false));
	
	vector<vector<int>> GraphList(vertices);
	
	for(int i = 0 ; i < edges ; i++){
	
		int a,b;
		cin >> a >> b;
		//GraphMatrix[a][b] = true;
		//GraphMatrix[b][a] = true;
		
		GraphList[a].push_back(b);
		GraphList[b].push_back(a);
		
	}
	
	/*
	
	for(int i = 0 ; i < vertices ; i++){
	
		cout << "Sasiedzi " << i << ": ";
		for(int sasiad : GraphList[i]) {
			cout << sasiad << " ";
		}
		cout << endl;
	}

	*/
	
	if (vertices == 0) {
    	cout << "graf spojny" << endl;
	} else {
    	if (dfs(0, GraphList)){
        	cout << "graf spojny" << endl;
    	} else { cout << "graf niespojny" << endl; }
	}

	
	
	return 0;
}

bool dfs(int v, vector<vector<int>> GraphList){

	int n = GraphList.size();
	stack<int> st;
	
	vector<bool> visited(n, false);
	vector<bool> to_visit(n, false);
	
	st.push(v);
	to_visit[v] = true;
	
	while(!st.empty()){
		
		int x = st.top();
		st.pop();
		
		if(visited[x]){ continue; }
		
		visited[x] = true;

		for(int y : GraphList[x]){
			if( !visited[y] and !to_visit[y] ){
				to_visit[y] = true;
				st.push(y);
			}
		}
		
	}

	for(int i = 0 ; i < visited.size() ; i++){
		//cout << visited[i] << endl;
		if (visited[i] == false ) { return false; }
	}
	
	return true;

	// check
	
}

// TO DO everything
