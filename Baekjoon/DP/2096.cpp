#include <iostream>
using namespace std;

int game[6];
int dp[6];

int main(void)
{
	int n;
	int maxNum = 0;
	int minNum = 1000000;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> game[j];
			game[j + 3] = game[j];
			if (i == 0)
			{
				dp[j] = game[j];
				dp[j + 3] = game[j];
			}
		}
		if (i == 0) continue;
		game[0] += max(dp[0], dp[1]);
		game[1] += max(dp[0], max(dp[1], dp[2]));
		game[2] += max(dp[1], dp[2]);
		game[3] += min(dp[3], dp[4]);
		game[4] += min(dp[3], min(dp[4], dp[5]));
		game[5] += min(dp[4], dp[5]);
		for (int j = 0; j < 6; j++)
		{
			dp[j] = game[j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (dp[i] > maxNum) maxNum = dp[i];
		if (dp[i + 3] < minNum) minNum = dp[i + 3];
	}
	cout << maxNum << " " << minNum;
	return 0;
}
