#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c;
int answer = 0;
bool visited[26];
char grid[20][20];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Dfs(int x, int y, int cnt)
{
	visited[grid[x][y] - 'A'] = true;
	if (answer < cnt)
	{
		answer = cnt;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx >= r || 0 > ny || ny >= c)
			continue;
		if (visited[grid[nx][ny] - 'A'])
			continue;
		Dfs(nx, ny, cnt + 1);
		visited[grid[nx][ny] - 'A'] = false;
	}
}

int	main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> grid[i][j];
		}
	}
	Dfs(0, 0, 1);
	cout << answer;
	return (0);
}
