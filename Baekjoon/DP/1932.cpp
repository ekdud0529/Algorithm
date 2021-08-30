#include <bits/stdc++.h>
using namespace std;

int num[500][500], dp[500][500];

int main(){
	int n, sum=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			cin >> num[i][j];
		}
	}
	
	dp[0][0] = num[0][0];
	for(int i=1; i<n; i++){
		for(int j=0; j<i+1; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + num[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		if(sum < dp[n-1][i]) sum = dp[n-1][i];
	}
	
	cout << sum;
	
	return 0;
}
