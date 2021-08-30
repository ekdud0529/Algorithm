#include<bits/stdc++.h>
using namespace std;

int a[1000], d1[1000], d2[1000];

int main(){
	int n, max=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		d1[i] = 1;
		for(int j=0; j<i; j++){
			if(a[i]>a[j] && d1[i]<d1[j]+1){
				d1[i] = d1[j]+1;
			}
		}
	}
	
	for(int i=n-1; i>=0; i--){
		d2[i] = 1;
		for(int j=n-1; j>i; j--){
			if(a[i]>a[j] && d2[i]<d2[j]+1){
				d2[i] = d2[j]+1;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		if(max < d1[i]+d2[i]-1){
			max = d1[i]+d2[i]-1;
		}
	}
	
	cout << max;
	
	return 0;
}
