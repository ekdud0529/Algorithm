#include <bits/stdc++.h>
using namespace std;

int a[10000001], b[10000000];

int main(int argc, char** argv) {
	int n, i, t, m, c;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t);
		if(t<0) b[-(t)]++;
		else a[t]++;
	}
	scanf("%d", &m);
	for(i=0;i<m;i++){
		c=0;
		scanf("%d", &t);
		if(t<0) printf("%d ", b[-(t)]);
		else printf("%d ", a[t]);
	}
	return 0;
}
