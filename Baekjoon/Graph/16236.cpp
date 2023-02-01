#include <iostream>
#include <queue>
using namespace std;

struct Feed
{
	int x;
	int y;
	int size;
	int dist;
};

int n;
Feed baby = { 0, 0, 2, 0 };
int cntFeed = 0;
int place[21][21];
int visited[21][21];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
int answer = 0;

void Clear()
{
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[k][j] = false;
		}
	}
}

Feed MostNear()
{
	Feed f = { 20, 20, 0, 1000000 };
	queue<Feed> q;

	q.push(baby);
	visited[baby.x][baby.y] = true;
	while (!q.empty())
	{
		Feed mv = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = mv.x + dx[i];
			int ny = mv.y + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
			if (place[nx][ny] > baby.size) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			if (place[nx][ny] && (place[nx][ny] < baby.size))
			{
				if ((mv.dist + 1) < f.dist) f = { nx, ny, 0, mv.dist + 1 };
				if ((mv.dist + 1) == f.dist)
				{
					if(f.x > nx) f = { nx, ny, 0, mv.dist + 1 };
					if (f.x == nx)
					{
						if (f.y > ny)
						{
							f = { nx, ny, 0, mv.dist + 1 };
						}
					}
				}
			}
			else
				q.push({ nx, ny, 0, mv.dist + 1 });
		}
	}
	return (f);
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> place[i][j];
			if (place[i][j] == 9)
			{
				baby.x = i;
				baby.y = j;
				place[i][j] = 0;
			}
		}
	}
}

int main()
{
	Input();
	while (1)
	{
		Clear();
		Feed f = MostNear();
		if ((f.x == 20) && (f.y == 20)) break;
		cntFeed += 1;
		if (cntFeed == baby.size)
		{
			baby.size += 1;
			cntFeed = 0;
		}
		baby.x = f.x;
		baby.y = f.y;
		answer += f.dist;
		place[f.x][f.y] = 0;
	}
	cout << answer;
	return 0;
}
