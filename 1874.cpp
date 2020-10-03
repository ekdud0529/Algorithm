#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n, m=0;
	string str;
	stack<int> s;
	cin >> n;
	
	while(n--){
		int x;
		cin >> x;
		if(x > m){
			while(x > m){
				s.push(++m);
				str += '+';
			}
			s.pop();
			str += '-';
		}
		else{
			bool found = false;
			if(!s.empty()){
				int top = s.top();
				s.pop();
				str += '-';
				if(x == top) found = true;
			}
			if(!found){
				cout << "NO";
				return 0;
			}
		}
	}
	for(char ch : str){
		cout << ch << "\n";
	}
	return 0;
}
