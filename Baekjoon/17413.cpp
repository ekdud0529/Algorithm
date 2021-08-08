#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	string str;
	getline(cin, str);
	bool tag = false;
	stack<char> s;
	for(char ch : str){
		if(ch == '<'){
			while(!s.empty()){
				cout << s.top();
				s.pop();
			}
			tag = true;
			cout << ch;
		}
		else if(ch == '>'){
			cout << ch;
			tag = false;
		}
		else if(tag){
			cout << ch;
		}
		else{
			if(ch == ' '){
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else{
				s.push(ch);
			}
		}
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	
	return 0;
}
