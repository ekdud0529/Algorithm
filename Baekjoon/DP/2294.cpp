#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coin[101];
int dp[100001];

int main(void)
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 100001;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	dp[0] = 0;
	sort(coin, coin + n);
	for (int i = 1; i <= k; i++)
	{
		if (i < coin[0]) dp[i] = -1;
		if (dp[i] == 1) continue;
		for (int  j = 0; j < n; j++)
		{
			if (i < coin[j]) break;
			if (dp[i - coin[j]] == -1) continue;
			if (i > coin[j])
			{
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}
	if (dp[k] != 100001) cout << dp[k];
	else cout << "-1";
	return 0;
}
