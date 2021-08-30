#include<bits/stdc++.h>
using namespace std;

int a[100000], d[100000], d2[100000];

int main(){
	int n, sum=-1001;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		d[i] = a[i];
		if(d[i-1]+a[i] > d[i]) d[i] = d[i-1]+a[i];
	}
	
	for(int i=n-1; i>=0; i--){
		d2[i] = a[i];
		if(d2[i+1]+a[i] > d2[i]) d2[i] = d2[i+1] + a[i];
	}
	
	for(int i=0; i<n; i++){
		if(i-1>=0 && i+1<n){
			sum = max(sum, d[i-1]+d2[i+1]);
		}
		sum = max(sum, d[i]);
	}
	
	cout << sum;
	
	return 0;
}
