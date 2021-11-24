#include <bits/stdc++.h>
using namespace std;

long long prime[1000001];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime[0] = 0;
	prime[1] = 1;
	for(int i=2; i<=1000000; i++)
	{
		for(int k=1; k*i<=1000000; k++)
		{
			prime[i * k] += i;
		}
		prime[i] += prime[i-1] + 1;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		cout << prime[n] << "\n";
	}
	return 0;
}
