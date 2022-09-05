#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n, K, m, t, nt, pre;

int swap(int num, int x, int y);
int	main(void)
{
	priority_queue<int> q[2];
	
	t = 0;
	nt = 1;
	cin >> n >> K;
	q[t].push(n);
	m = 0;
	while (n)
	{
		m++;
		n /= 10;
	}
	for (int i = 0; i < K; i++)
	{
		pre = -1;
		while (!q[t].empty())
		{
			int num = q[t].top();
			q[t].pop();
			if (pre == num) continue;
			pre = num;
			for (int j = 0; j < m; j++)
			{
				for (int k = j + 1; k < m; k++)
				{
					int next = swap(num, j, k);
					if (next != -1)
						q[nt].push(next);
				}
			}
		}
		t = nt;
		nt = (nt + 1) & 1;
	}
	if (q[t].empty())
		cout << "-1";
	else
		cout << q[t].top();
	return (0);
}

int swap(int num, int x, int y)
{
	int xn = pow(10, x);
	int yn = pow(10, y);
	int a = ((num / xn) % 10);
	int b = ((num / yn) % 10);

	if (a == 0 && y == m - 1)
		return (-1);
	return num - (a * xn + b * yn) + (a * yn + b * xn);
}
