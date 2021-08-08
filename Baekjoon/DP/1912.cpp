#include <bits/stdc++.h>
using namespace std;

int a[100001], d[100001];

int main(int argc, char** argv) {
	int n, max=-1000;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n; i++){
		d[i] = a[i];
		if(d[i-1]+a[i] > d[i]) d[i] = d[i-1]+a[i];
		if(d[i] > max) max = d[i];
	}
	
	printf("%d", max);
	return 0;
} 
