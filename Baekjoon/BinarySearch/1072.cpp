#include <iostream>
using namespace std;

int main()
{
	long long x, y;
	cin >> x >> y;
	long long z = (y * 100 / x);

	if (z >= 99)
		cout << -1;
	else
	{
		long long left = 1;
		long long right = x;
		long long mid = 0;
		long long result = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			long long newZ = ((y + mid) * 100 / (x + mid));
			if (newZ > z)
			{
				result = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << result;
	}
	return 0;
}
