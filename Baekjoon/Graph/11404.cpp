#include <iostream>
using namespace std;

int graph[101][101];

void Clear(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 100000000;
		}
	}
}

void FloydWarshall(int n)
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

int main()
{
	int n, m;

	cin >> n >> m;
	Clear(n);
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if(graph[start][end] > cost)
			graph[start][end] = cost;
	}
	FloydWarshall(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == 100000000)
				cout << "0 ";
			else cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
