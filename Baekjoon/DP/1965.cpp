#include <bits/stdc++.h>
using namespace std;

int box[1000];
int dp[1000];

int get_max(int n)
{
	int cnt_max = 0;
	for(int i=0; i<n; i++)
	{
		dp[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(box[j] < box[i])
				dp[i] = max(dp[i], dp[j] + 1);
			if(dp[i] > cnt_max) cnt_max = dp[i];
		}
	}
	return cnt_max;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> box[i];
	}
	cout << get_max(n);
	return 0;
}
