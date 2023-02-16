#include <iostream>
using namespace std;

int GetMinLen(int n, int s, int num[])
{
	int left = 0;
	int right = 0;
	int sum = num[right];
	int ans = n;

	while (right < n)
	{
		if (sum >= s)
		{
			int len = right - left + 1;
			if (left == right)
			{
				len = 1;
			}
			if (ans > len)
			{
				ans = len;
			}
			sum -= num[left];
			left++;
		}
		else
		{
			right++;
			if(right < n)
				sum += num[right];
		}
	}
	return (ans);
}

int main(void)
{
	int n, s;
	int num[100000];
	int sum = 0;

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		sum += num[i];
	}
	if (sum < s)
	{
		cout << 0;
	}
	else
	{
		cout << GetMinLen(n, s, num);
	}
	return (0);
}
