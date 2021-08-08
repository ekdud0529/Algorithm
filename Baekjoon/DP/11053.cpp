#include <bits/stdc++.h>
using namespace std;

int a[1001], len[1001];

int main(int argc, char** argv) {
	int n, max=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		len[i] = 1;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i]>a[j] && len[i]<=len[j]){
				len[i]++;
			}
		}
		if(len[i] > max) max = len[i];
	}
	
	printf("%d", max);
	
	return 0;
}
