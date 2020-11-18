#include <bits/stdc++.h>
using namespace std;

int cd[1001], p[1001];

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &p[i]);
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cd[i] = max(cd[i], cd[i-j]+p[j]);
		}
	}
	
	printf("%d", cd[n]);
	return 0;
}
