#include <iostream>
using namespace std;

int n, e, v1, v2;
long long graph[801][801];
long long answer = 0;

void FloydWarshall()
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
	cin >> n >> e;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 100000000;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		cin >> graph[n1][n2];
		graph[n2][n1] = graph[n1][n2];
	}
	cin >> v1 >> v2;
	FloydWarshall();
	answer = min(graph[1][v1] + graph[v1][v2] + graph[v2][n], graph[1][v2] + graph[v2][v1] + graph[v1][n]);
	if (answer >= 100000000) answer = -1;
	cout << answer;
	return 0;
}
