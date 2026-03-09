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

void dfs(int v,vector<vector<int>> GraphList, vector<bool>& visited);

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
	
	int n = GraphList.size();
	vector<bool> visited(n, false);

	int count = 0;

	for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, GraphList, visited);
            count++;
        }
    }


	cout << "Liczba skladowych: " << count << endl;

	return 0;
}

void dfs(int v, vector<vector<int>> GraphList, vector<bool>& visited){

	stack<int> st;
	
	vector<bool> to_visit(GraphList.size(), false);
	
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

	// check
	
}
