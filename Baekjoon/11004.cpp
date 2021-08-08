#include <bits/stdc++.h>
using namespace std;

int t[5000001];

int main(int argc, char** argv) {
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i=0;i<n;i++){
		scanf("%d", &t[i]);
	}
	sort(t, t+n);
	printf("%d", t[k-1]);
	return 0;
}
