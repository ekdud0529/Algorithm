#include<bits/stdc++.h>
using namespace std;

int dp[31];

int main(){
	int n;
	cin >> n;
	
	dp[0] = 1;
	dp[2] = 3;
	for(int i=4; i<=n; i+=2){
		for(int j=2; j<=i; j+=2){
			if(j==2) dp[i] += dp[i-j]*3;
			else dp[i] += dp[i-j]*2;
		}
	}
	
	cout << dp[n];
	
	return 0;
}
