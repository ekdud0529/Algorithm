#include <bits/stdc++.h>
using namespace std;

long long b[91][3];

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	
	b[1][0] = 0;
	b[1][1] = 1;
	
	for(int i=2; i<=n; i++){
		b[i][0] = b[i-1][0]+b[i-1][1];
		b[i][1] = b[i-1][0];
	}
	
	printf("%lld", b[n][0]+b[n][1]);
	return 0;
}
