
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

	stack<char> okragle;
	stack<char> kwadratowe;
	stack<char> klamrowe;

	stack<char> otwarte;

	string nawiasy;

	cin >> nawiasy;

	for(int i = 0 ; i < nawiasy.length() ; i++){
		if(nawiasy[i] == '('){
			okragle.push('(');
			otwarte.push('(');
		}
		else if(nawiasy[i] == '['){
			kwadratowe.push('[');
			otwarte.push('[');
		}
		else if(nawiasy[i] == '{'){
			klamrowe.push('{');
			otwarte.push('{');
		}

		//

		if(otwarte.empty()){
			cout << "nie" << endl;
			return 0;
		}

		if(nawiasy[i] == ')'){

			if(otwarte.top() != '('){
				cout << "nie" << endl;
				return 0;
			}
			otwarte.pop();
			if(okragle.empty()){
				cout << "nie" << endl;
				return 0;
			} else{ okragle.pop(); }
		}
		else if(nawiasy[i] == ']'){

			if(otwarte.top() != '['){
				cout << "nie" << endl;
				return 0;
			}
			otwarte.pop();
			if(kwadratowe.empty()){
				cout << "nie" << endl;
				return 0;
			} else{ kwadratowe.pop(); }
		}
		else if(nawiasy[i] == '}'){

			if(otwarte.top() != '{'){
				cout << "nie" << endl;
				return 0;
			}
			otwarte.pop();
			if(klamrowe.empty()){
				cout << "nie" << endl;
				return 0;
			} else{ klamrowe.pop(); }
		}

	}

	if(okragle.empty() and kwadratowe.empty() and klamrowe.empty()){
		cout << "tak" << endl;
	} else {
		cout << "nie" << endl;
	}

	return 0;
}