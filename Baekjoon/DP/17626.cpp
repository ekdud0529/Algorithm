#include<bits/stdc++.h>
using namespace std;

int num[50001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	
	int n;
	cin >> n;
	
	num[1] = 1;
	for(int i=2; i<=n; i++){
		num[i] = 1+num[i-1];
		
		for(int j=2; j*j<=i; j++){
			num[i] = min(num[i], 1+num[i-j*j]);
		}
	}
	
	cout << num[n];
	return 0;
}
