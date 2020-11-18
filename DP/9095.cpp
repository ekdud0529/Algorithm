//Top-down
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

//Bottom-up
#include <bits/stdc++.h>
using namespace std;

int sum[12];

int main(int argc, char** argv) {
	int t, n;
	scanf("%d", &t);
	
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	
	for(int i=4; i<=11; i++){
		sum[i] = sum[i-1]+sum[i-2]+sum[i-3];
	}
	
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("%d\n", sum[n]);
	}
	return 0;
}
