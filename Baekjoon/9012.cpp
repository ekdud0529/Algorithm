#include <bits/stdc++.h>
using namespace std;

string s;

int main(int argc, char** argv) {
	int n, top, i, cnt;
	cin >> n;
	while(n--){
		cin >> s;
		cnt = s.size();
		top=-1;
		for(i=0;i<cnt;i++){
			if(s[i]=='(') top++;
			else if(s[i]==')'){
				if(top<0){
					top--;
					break;
				}
				else top--;
			}
		}
		if(top==-1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
