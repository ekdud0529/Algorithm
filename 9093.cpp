#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string str;
		getline(cin, str);
		str+='\n';
		stack<char> s;
		
		for(char a : str){
			if(a == ' ' || a == '\n'){
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				cout << a;
			}
			else{
				s.push(a);
			}
		}
	}
	
	return 0;
}
