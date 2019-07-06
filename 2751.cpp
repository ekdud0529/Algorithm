#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i;
	scanf("%d", &n);
	int a[n+1];
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	for(i=0;i<n;i++){
		printf("%d\n", a[i]);
	}
	return 0;
}
