#include <iostream>
using namespace std;

long long op[100][21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int num;

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> num;
		if (i == 0)
			op[i][num] += 1;
		else
		{
			for (int j = 0; j <= 20; j++)
			{
				if (op[i - 1][j] > 0)
				{
					if(0 <= j + num && j + num <= 20)
						op[i][j + num] += op[i - 1][j];
					if (0 <= j - num && j - num <= 20)
						op[i][j - num] += op[i - 1][j];
				}
			}
		}
	}
	cin >> num;
	cout << op[n - 2][num];
	return 0;
}
