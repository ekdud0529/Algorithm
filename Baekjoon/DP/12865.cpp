#include <bits/stdc++.h>
using namespace std;

int	bag[101][2];
int dp[101][100001];

int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++)
	{
		cin >> bag[i][0] >> bag[i][1];
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(j - bag[i][0] < 0)
			{
				dp[i][j] = dp[i-1][j];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-bag[i][0]]+bag[i][1]);
		}
	}
	cout << dp[n][k];
	return 0;
}
