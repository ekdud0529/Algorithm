#include <iostream>
#include <vector>
using namespace std;

int w, h;
int rect[50][50];
bool visited[50][50];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int cnt = 0;

void getCnt(int x, int y)
{
	for (int k = 0; k < 8; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (visited[nx][ny] || rect[nx][ny] == 0) continue;
		if (0 > nx || nx >= h || 0 > ny || ny >= w)
			continue;
		visited[nx][ny] = true;
		getCnt(nx, ny);
	}
}

void setEmpty()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			visited[i][j] = false;
			rect[i][j] = 0;
		}
	}
}

int main()
{
	while (1)
	{
		cin >> w >> h;

		if (!w && !h) break;

		setEmpty();

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> rect[i][j];
			}
		}

		cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] || rect[i][j] == 0) continue;
				cnt++;
				visited[i][j] = true;
				getCnt(i, j);
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
