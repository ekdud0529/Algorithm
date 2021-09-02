#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, len=0;
	long long cnt=0;
	cin >> n;
	
	for(int i=1; i<=n; i*=10){
		int end = i*10-1;
		len++;
		if(end>n){
			end = n;
		}
		cnt += (long long)(end-i+1)*len;
	}
	cout << cnt;
	
	return 0;
}
