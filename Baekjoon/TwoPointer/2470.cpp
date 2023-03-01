#include <iostream>
#include <algorithm>
using namespace std;

int water[100000];
int answer = 2000000001;
int l, r;

void GetSpecial(int start, int end)
{
	while (start < end)
	{
		int ans = water[start] + water[end];
		if (abs(0 - ans) < abs(0 - answer))
		{
			answer = ans;
			l = start;
			r = end;
		}
		if (ans == 0)
		{
			return;
		}
		else if (ans > 0)
		{
			end--;
		}
		else if (ans < 0)
		{
			start++;
		}
	}
}

int	main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> water[i];
	}
	sort(water, water + n);
	GetSpecial(0, n-1);
	cout << water[l] << " " << water[r];
	return (0);
}
