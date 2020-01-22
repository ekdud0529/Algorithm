#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, m, cnt=0;
	scanf("%d %d", &n, &m);
	map<string, int> mp;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		mp[str] = 1;
	}
	for(int i=0; i<m; i++){
		string str;
		cin >> str;
		if(mp[str]==1){
			cnt++;
			mp[str] = 2;
		}
	}
	printf("%d\n", cnt);
	for(map<string, int>::iterator i=mp.begin(); i!=mp.end(); i++){
		if(i -> second == 2) printf("%s\n", (i->first).c_str());
	}
	return 0;
}
