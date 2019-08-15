#include <bits/stdc++.h>
using namespace std;

int t[101], p[101];

int main(int argc, char** argv) {
	int n, i, k=1;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t[i]);
		p[i] = t[i]*k-t[i-1]*(k-1);
		k++;
        printf("%d ", p[i]);
	}
	return 0;
}
