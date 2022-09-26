#include <iostream>
using namespace std;

bool checkPrime(int pm, string p)
{
	int num = 0;

	for (int i = 0; i < p.size(); i++)
	{
		num = ((num * 10) + (p[i] - '0')) % pm;
	}
	if (num == 0)
	{
		cout << "BAD " << pm;
		return (true);
	}
	return (false);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string p;
	int k;
	
	cin >> p >> k;
	
	for (int i = 2; i < k; i++)
	{
		if (checkPrime(i, p))
		{
			return (0);
		}
	}
	cout << "GOOD";
	return (0);
}
