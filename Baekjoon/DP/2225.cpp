#include<bits/stdc++.h>
using namespace std;

int dp[201][201];

int main(){
	int n, k;
	cin >> n >> k;
	
	dp[0][0] = 1;
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][j-k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	
	cout << dp[k][n];
	return 0;
}
