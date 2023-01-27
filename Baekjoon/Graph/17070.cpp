#include <iostream>
#include <queue>
using namespace std;

struct Pipe
{
	int fx, fy;
	int bx, by;
	int mode;
};

int n;
int answer = 0;
int home[16][16];
int dx[7] = {0, 1, 1, 1, 0, 1, 1};
int dy[7] = {1, 1, 0, 1, 1, 0, 1};

void bfs(void)
{
	queue<Pipe> q;

	q.push({ 0, 0, 0, 1, 0 });
	while (!q.empty())
	{
		Pipe pipe = q.front();
		int start, end;
		q.pop();
		if (pipe.bx == n - 1 && pipe.by == n - 1)
		{
			answer++;
			continue;
		}
		pipe.fx = pipe.bx;
		pipe.fy = pipe.by;
		if (pipe.mode == 0)
		{
			start = 0;
			end = 2;
		}
		else if (pipe.mode == 1)
		{
			start = 2;
			end = 4;
		}
		else
		{
			start = 4;
			end = 7;
		}
		for (; start < end; start++)
		{
			int nx = pipe.bx + dx[start];
			int ny = pipe.by + dy[start];
			int mode = 0;
			if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
			if (home[nx][ny]) continue;
			if (dx[start] && dy[start])
			{
				if (home[nx - 1][ny] || home[nx][ny - 1]) continue;
			}
			if (dx[start] == 0) mode = 0;
			else if (dy[start] == 1) mode = 2;
			else mode = 1;
			q.push({pipe.fx, pipe.fy, nx, ny, mode});
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> home[i][j];
		}
	}
	bfs();
	cout << answer;
	return 0;
}
