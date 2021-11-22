#include <bits/stdc++.h>
using namespace std;

int prime[50];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> prime[i];
	}

	sort(prime, prime + n);

	cout << prime[0] * prime [n-1];
	return 0;
}
