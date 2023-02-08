#include <iostream>
using namespace std;

int dp[1000001];

int main(void)
{
	int n;

	cin >> n;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = i - 1;
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (dp[i] > dp[i - 1] + 1)
		{
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
	}
	cout << dp[n] << "\n";
	while (1)
	{
		cout << n << " ";
		if (n == 1) break;
		int num = n;
		if (n % 3 == 0)
		{
			num = n / 3;
		}
		if (n % 2 == 0)
		{
			if (dp[num] > dp[n / 2])
				num = n / 2;
		}
		if (dp[num] > dp[n - 1])
			num = n - 1;
		n = num;
	}
	return 0;
}
