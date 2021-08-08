#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	string str;
	getline(cin, str);
	stack<int> s;
	int cnt = 1, sum=0;
	
	for(char ch : str){
		if(ch == '('){
			s.push(cnt);
		}
		else if(ch == ')'){
			if(s.top()+1 != cnt){
				s.pop();
				sum++;
			}
			else{
				s.pop();
				sum += s.size();
			}
		}
		cnt++;
	}
	
	cout << sum;
	
	return 0;
}
