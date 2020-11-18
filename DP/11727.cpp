#include <bits/stdc++.h>
using namespace std;

long long t[1001];

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	t[1] = 1;
	t[2] = 3;
		
	for(int i=3; i<=n; i++){
		t[i] = (t[i-1] + t[i-2] + t[i-2])%10007;
	}
	
	printf("%lld", t[n]);
	return 0;
}
