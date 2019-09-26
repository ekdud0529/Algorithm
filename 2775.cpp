#include <bits/stdc++.h>
using namespace std;

int a[15][15];

int main(int argc, char** argv) {
	int t, k, n, j, u;
	scanf("%d", &t);
	for(j=1;j<=14;j++){
		for(u=1;u<=14;u++){
			if(j==1) a[j][u] = u*(u+1)/2;
			else a[j][u] = a[j-1][u] + a[j][u-1];
		}
	}
	for(j=0;j<t;j++){
		scanf("%d %d", &k, &n);
		printf("%d\n", a[k][n]);
	}
	return 0;
}
