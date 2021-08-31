#include <bits/stdc++.h>
using namespace std;

int home[1000][3], dp[1000][3];

int main(){
	int n, sum=1000001;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> home[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		// 1house color select
		for(int j=0; j<3; j++){
			if(i == j) dp[0][j] = home[0][j];
			else dp[0][j] = 1000001;
		}
		
		for(int j=1; j<n; j++){
			dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + home[j][0];
			dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + home[j][1];
			dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + home[j][2];
		}
		
		for(int k=0; k<3; k++){
			if(i == k) continue;
			if(sum > dp[n-1][k]) sum = dp[n-1][k];
		}
	}
	cout << sum;
	
	return 0;
}
