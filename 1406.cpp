#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	stack<char> left, right;
	string str;
	cin >> str;
	for(char ch : str) left.push(ch);
	
	int t;
	cin >> t;
	while(t--){
		char op;
		cin >> op;
		if(op == 'L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		else if(op == 'D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
		else if(op =='B'){
			if(!left.empty()){
				left.pop();
			}
		}
		else if (op == 'P'){
			char c;
			cin >> c;
			left.push(c);
		}
	}
	
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	
	while(!right.empty()){
		cout << right.top();
		right.pop();
	}
	
	return 0;
}
