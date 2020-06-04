#include <bits/stdc++.h>
using namespace std;

int dp[12];

int f(int n){
	if(dp[n]) return dp[n];
	if(n==1) return dp[1] = 1;
	else if(n==2) return dp[2] = 2;
	else if(n==3) return dp[3] = 4;
	return dp[n] = f(n-1) + f(n-2) + f(n-3);
}

int main(int argc, char** argv) {
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
