#include <bits/stdc++.h>
using namespace std;

int dp[100000][3];

int main(){
	int n;
	cin >> n;
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<3; j++){
			if(j == 1){
				dp[i][j] += (dp[i-1][0] + dp[i-1][2])%9901;
			}
			else if(j == 2){
				dp[i][j] += (dp[i-1][0] + dp[i-1][1])%9901;
			}
			else{
				dp[i][j] += (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
			}
		}
	}
	cout << (dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%9901;
	
	return 0;
}
