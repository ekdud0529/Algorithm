#include <iostream>
using namespace std;

int tc, n, m, w;
int graph[501][501];

void Clear(void)
{
	for (int i = 0; i <= 500; i++)
	{
		for (int j = 0; j <= 500; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 10000;
		}
	}
}

void Input(void)
{
	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		if (graph[a][b] != 10000)
		{
			graph[a][b] = min(graph[a][b], t);
			graph[b][a] = graph[a][b];
		}
		else
		{
			graph[a][b] = t;
			graph[b][a] = t;
		}
	}
	for (int i = 0; i < w; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		if (graph[a][b] != 10000)
			graph[a][b] = min(graph[a][b], -t);
		else
			graph[a][b] = -t;
	}
}

void Floyd(void)
{
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				graph[i][k] = min(graph[i][k], graph[i][j] + graph[j][k]);
			}
		}
	}
}

string CheckW()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((graph[i][j] + graph[j][i]) < 0)
			{
				return ("YES\n");
			}
		}
	}
	return ("NO\n");
}

int main(void)
{
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> w;
		Clear();
		Input();
		Floyd();
		cout << CheckW();
		
	}
	return (0);
}
