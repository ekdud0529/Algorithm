#include <iostream>
using namespace std;

int GCD(int k, int c)
{
	if (c == 0)
		return (k);
	return (GCD(c, k % c));
}

void getCandy(int k, int c)
{
	int K = k;
	int r;
	int q;
	int tmp;
	int t1 = 0;
	int t2 = 1;

	while (c != 0)
	{
		q = k / c;
		r = k % c;
		tmp = t1 - (q * t2);
		t1 = t2;
		t2 = tmp;
		k = c;
		c = r;
	}
	while (t1 < 0)
	{
		t1 += K;
	}
	if (t1 > 1000000000)
		cout << "IMPOSSIBLE\n";
	else
		cout << t1 << "\n";
	return;
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;

	cin >> t;
	while (t--)
	{
		int k, c;
		cin >> k >> c;
		int gcd = GCD(k, c);
		if (gcd != 1)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		if (k == 1 && c == 1)
			cout << "2\n";
		else if (k == 1)
			cout << "1\n";
		else if (c == 1)
		{
			if (k + 1 > 1000000000)
				cout << "IMPOSSIBLE\n";
			else
				cout << k + 1 << "\n";
		}
		else
			getCandy(k, c);
	}
	return (0);
}
