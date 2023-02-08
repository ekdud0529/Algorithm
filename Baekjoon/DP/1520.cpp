#include <iostream>
using namespace std;

int map[500][500];
int dp[500][500];
int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y)
{
	if ((x == n - 1) && (y == m - 1))
	{
		return (1);
	}
	if (dp[x][y] != -1)
	{
		return (dp[x][y]);
	}
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
		if (map[x][y] <= map[nx][ny]) continue;
		dp[x][y] += dfs(nx, ny);
	}
	return (dp[x][y]);
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout <<  dfs(0, 0);
	return 0;
}
