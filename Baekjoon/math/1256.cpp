#include <iostream>
using namespace std;

long long comb[201][201];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, len;
	long long k;

	cin >> n >> m >> k;
	comb[0][0] = 1;
	for (int i = 1; i <= 200; i++)
	{
		comb[i][0] = 1;
		comb[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			if (comb[i][j] > 1000000000)
				comb[i][j] = 1000000001;
		}
	}
	if (comb[n + m][m] < k)
	{
		cout << "-1";
		return (0);
	}
	len = n + m;
	for (int i = len; i > 0; i--)
	{
		if (comb[i - 1][m] < k)
		{
			cout << 'z';
			k -= comb[i - 1][m];
			m--;
		}
		else
		{
			cout <<  'a';
		}
	}
	return (0);
}
