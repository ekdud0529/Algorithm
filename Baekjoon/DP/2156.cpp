#include <bits/stdc++.h>
using namespace std;

int grape[10000], d[10000];

int main(){
	int n, sum=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> grape[i];
	}
	
	for(int i=0; i<n; i++){
		d[i] = max(d[i-1], max(d[i-2]+grape[i], d[i-3]+grape[i-1]+grape[i]));
	}
	
	cout << d[n-1];
	return 0;
}
