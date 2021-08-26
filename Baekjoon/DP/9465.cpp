#include <bits/stdc++.h>
using namespace std;

int st[2][100000];
int dp[100000][3];

int main(){
	int t;
	cin >> t;
	
	for(int k=0; k<t; k++){
		int n;
		cin >> n;
		
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin >> st[i][j];
			}
		}
		
		dp[0][0] = 0;
		dp[0][1] = st[0][0];
		dp[0][2] = st[1][0];
		for(int i=1; i<n; i++){
			dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + st[0][i];
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + st[1][i];
			dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		}
		cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
	}
	
	return 0;
}
