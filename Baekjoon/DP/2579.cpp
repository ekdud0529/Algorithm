#include <bits/stdc++.h>
using namespace std;

int n;
int stair[300];
int dp[300];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> stair[i];
	}
	
	dp[0] = stair[0];
	dp[1] = max(dp[0]+stair[1], stair[1]);
	dp[2] = max(stair[1]+stair[2], stair[0]+stair[2]);
	
	for(int i=3; i<n; i++)
	{
		dp[i] = max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
	}
	cout << dp[n-1];
	return 0;
}
