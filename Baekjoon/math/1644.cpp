#include <iostream>
using namespace std;

int prime[4000001];
int check[4000001];

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int index = 0;
	int a = 0;
	int b = 0;
	int cnt = 0;
	int sum = 0;

	cin >> n;
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 4000000; i++)
	{
		if (check[i]) continue;
		prime[index++] = i;
		for (int j = i + i; j <= 4000000; j += i)
		{
			check[j] = true;
		}
	}
	while (b <= index)
	{
		if (prime[b] > n)
			break;
		sum += prime[b];
		if (sum > n)
		{
			while (a <= b && sum > n)
			{
				sum -= prime[a];
				a++;
			}
		}
		if (sum == n)
		{
			cnt++;
			sum -= prime[a];
			a++;
		}
		b++;
	}
	cout << cnt;
	return (0);
}
