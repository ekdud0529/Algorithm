#include <bits/stdc++.h>
using namespace std;

int num[100001];
int dp[100001];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		cin >> num[i];
		dp[i] = num[i]+dp[i-1];
	}
	
	for(int k=0; k<m; k++)
	{
		int i, j;
		cin >> i >> j;
		
		cout << dp[j] - dp[i-1] << "\n";
	}
	
	return 0;
}
