#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main(int argc, char *argv[]) {
	int n, c, i, k, j, b;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(b=n-1;b>0;b--){
		for(k=0;k<b;k++){
		if(a[k]>a[k+1]){
			c = a[k];
			a[k] = a[k+1];
			a[k+1] = c;
			}
		}
	}
	for(j=0;j<n;j++){
		printf("%d\n", a[j]);
	}
	return 0;
}
