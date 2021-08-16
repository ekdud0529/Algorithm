#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	string s;
	cin >> s;
	int size = s.size();
	
	if(size%3 == 1) cout << s[0];
	else if(size%3 == 2) cout << (s[0]-'0')*2 + (s[1]-'0');
	
	for(int i=size%3; i<size; i+=3){
		cout << (s[i]-'0')*4 + (s[i+1]-'0')*2 + (s[i+2]-'0');
	}
	
	return 0;
}
