#include <bits/stdc++.h>
using namespace std;

int value[100];
int dp[100001];

int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++)
	{
		cin >> value[i];
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++)
	{
		for(int j=value[i-1]; j<=k; j++)
		{
			dp[j] = dp[j] + dp[j - value[i-1]];
		}
	}
	cout << dp[k];
	return 0;
}
