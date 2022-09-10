#include <iostream>
using namespace std;

int		n, m;
int		dy[4] = { 0, 0, -1, 1 };
int		dx[4] = { 1, -1, 0, 0 };
int		map[300][300];
bool	visited[300][300];
int		cnt_melt[300][300];
int		cnt_time = 0;

void	getClean()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				visited[i][j] = true;
			else
				visited[i][j] = false;
			cnt_melt[i][j] = 0;
		}
	}
}

void	bfs(int x, int y)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = dx[k] + x;
		int ny = dy[k] + y;

		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
		continue;
		if (visited[nx][ny] || map[nx][ny] == 0)
			continue;
		visited[nx][ny] = true;
		bfs(nx, ny);
	}
}

bool	cntIce()
{
	int	cnt = 0;
	bool flag = false;

	getClean();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0) flag = true;
			if (visited[i][j]) continue;
			visited[i][j] = true;
			bfs(i, j);
			cnt++;
		}
	}
	if (!flag)
	{
		cout << "0";
		exit(0);
	}
	if (cnt >= 2)
		return (true);
	return (false);
}

void	melt()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cnt_melt[i][j] != 0)
			{
				map[i][j] -= cnt_melt[i][j];
				if (map[i][j] < 0)
					map[i][j] = 0;
			}
		}
	}
}

void	getMelt()
{
	cnt_time++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (map[nx][ny] == 0)
					cnt_melt[i][j]++;
				if (map[i][j] == 0)
					break ;
			}
		}
	}
	melt();
	if (!cntIce())
		getMelt();
	else
		return ;
}

int	main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	if (cntIce())
		cout << "0";
	else getMelt();
	cout << cnt_time;
	return (0);
}
