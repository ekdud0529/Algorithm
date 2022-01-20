#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[101][101];

void floydwarshall()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=1; k<=n; k++)
			{
				if(graph[j][i] + graph[i][k] < graph[j][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		for(int k=1; k<=n; k++)
		{
			if(i == k) graph[i][k] = 0;
			else graph[i][k] = 1000000;
		}
	}
	
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	floydwarshall();
	
	int sum_min = 10000000;
	int index = 0;
	for(int i=1; i<=n; i++)
	{
		int sum = 0;
		for(int k=1; k<=n; k++)
		{
			sum += graph[i][k];
		}
		if(sum_min > sum)
		{
			sum_min = sum;
			index = i;
		}
	}
	
	cout << index;
	return 0;
}
