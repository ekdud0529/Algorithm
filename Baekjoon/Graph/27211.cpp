#include <iostream>
using namespace std;

int n, m;
int donut[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx) nx = n + nx;
		if (n <= nx) nx %= n;
		if (0 > ny) ny = m + ny;
		if (m <= ny) ny %= m;
		if (visited[nx][ny] || donut[nx][ny] == 1) continue;
		visited[nx][ny] = true;
		bfs(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> donut[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || donut[i][j] == 1) continue;
			visited[i][j] = true;
			cnt++;
			bfs(i, j);
		}
	}
	cout << cnt;
	return 0;
}
