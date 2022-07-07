#include <iostream>
using namespace std;

bool rm[1001];

int main()
{
	int n, k;
	int cnt = 0;

	cin >> n >> k;
	
	for (int i = 2; i <= n; i++)
	{
		if (rm[i]) continue;
		for (int j = 1; i*j <= n; j++)
		{
			if (rm[i * j]) continue;
			cnt++;
			rm[i * j] = true;
			if (cnt == k)
			{
				cout << i * j;
				break;
			}
		}
		if (cnt == k) break;
	}
	return 0;
}
