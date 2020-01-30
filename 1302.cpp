#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	map<string, int> mp;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		mp[str]++;
	}
	string max;
	int m=0;
	for(map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++){
		if(it->second > m){
			max = it->first;
			m = it->second;
		}
	}
	cout << max;
	return 0;
}
