#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int grid[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Bfs(int x, int y)
{
	queue<pair<int, int>> q;

	q.push({ x, y });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= m)
				continue;
			if (grid[nx][ny] == -1 || grid[nx][ny] == 1)
				continue;
			q.push({ nx, ny });
			grid[nx][ny] = -1;
		}
	}
}

void CheckAir()
{
	for (int i = 0; i < n; i++)
	{
		if (grid[i][0] != -1)
		{
			Bfs(i, 0);
		}
		
		else if (grid[i][n - 1] != -1)
		{
			Bfs(i, n - 1);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (grid[0][i] != -1)
		{
			Bfs(0, i);
		}
		else if (grid[m - 1][i] != -1)
		{
			Bfs(n - 1, i);
		}
	}
}

bool CheckMelt(int x, int y)
{
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx >= n || 0 > ny || ny >= m)
			continue;
		if (grid[nx][ny] == -1)
			cnt++;
	}
	if (cnt >= 2)
	{
		return (true);
	}
	return (false);
}

int	main(void)
{
	int cnt = 0;
	int answer = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				cnt++;
		}
	}
	while (cnt != 0)
	{
		answer++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == -1)
					grid[i][j] = 0;
			}
		}
		CheckAir();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == -1)
					continue;
				if (CheckMelt(i, j))
				{
					grid[i][j] = 0;
					cnt--;
				}
			}
		}
	}
	cout << answer;
	return (0);
}
