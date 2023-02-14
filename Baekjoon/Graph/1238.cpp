#include <iostream>
using namespace std;

int n, m, x;
int graph[1001][1001];

void Floyd(void)
{
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 0; k <= n; k++)
			{
				if (graph[i][k] > (graph[i][j] + graph[j][k]))
				{
					graph[i][k] = graph[i][j] + graph[j][k];
				}
			}
		}
	}
}

int main(void)
{
	int answer = 0;

	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			graph[i][j] = 1000000;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int start, end, t;
		cin >> start >> end >> t;
		graph[start][end] = t;
	}
	Floyd();
	for (int i = 1; i <= n; i++)
	{
		if (answer < (graph[i][x] + graph[x][i]))
		{
			answer = graph[i][x] + graph[x][i];
		}
	}
	cout << answer;
	return 0;
}
