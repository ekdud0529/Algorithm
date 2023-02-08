#include <iostream>
using namespace std;

int n, m, r;
int item[101];
int graph[101][101];

void FloydWarshall(void)
{
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (graph[i][k] > (graph[i][j] + graph[j][k]))
				{
					graph[i][k] = graph[i][j] + graph[j][k];
				}
			}
		}
	}
}

int GetMaxItem(void)
{
	int itemCnt = 0;

	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] <= m)
			{
				cnt += item[j];
			}
		}
		if (itemCnt < cnt) itemCnt = cnt;
	}
	return (itemCnt);
}

int main(void)
{
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 10000;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}
	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
	FloydWarshall();
	cout << GetMaxItem();
	return 0;
}
