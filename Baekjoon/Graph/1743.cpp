#include <iostream>
#include <stack>
using namespace std;

int n, m, k;
int biggest = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int road[101][101];
bool visited[101][101];

int getBiggestTrash(int x, int y, int size)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx <= 0 || nx > n || ny <= 0 || ny > m)
			continue;
		if (visited[nx][ny] || road[nx][ny] == 0) continue;
		visited[nx][ny] = true;
		size = getBiggestTrash(nx, ny, size + 1);
	}
	return size;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		road[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visited[i][j] || road[i][j] == 0) continue;
			visited[i][j] = true;
			int size = getBiggestTrash(i, j, 1);
			if (size > biggest) biggest = size;
		}
	}
	cout << biggest;
	return 0;
}
