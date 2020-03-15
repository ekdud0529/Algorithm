#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, k, a=1, b=1, c=1;
	scanf("%d %d", &n, &k);
	for(int i=2; i<=n; i++) a*=i;
	for(int j=2; j<=k; j++) b*=j;
	for(int x=2; x<=n-k; x++) c*=x;
	printf("%d", a/(b*c));
	return 0;
}
