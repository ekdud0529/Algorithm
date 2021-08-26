#include <bits/stdc++.h>
using namespace std;

int d[1000001];

int main(){
	int t;
	cin >> t;
	
	d[0] = 1;
	d[1] = 1;
	for(int i=2; i<=1000000; i++){
		for(int j=1; j<=3; j++){
			if(i >= j) d[i] += d[i-j];
			d[i] %= 1000000009;
		}
	}
	
	while(t--){
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}
	
	return 0;
}
