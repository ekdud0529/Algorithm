#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
	int x, y;
};

int n, m;
int answer = 0;
int lab[8][8];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<Pos> emp;

void CntSafe(int labCopy[8][8])
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (labCopy[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	if (cnt > answer) answer = cnt;
}

void setVirus(int labCopy[8][8])
{
	queue<Pos> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (labCopy[i][j] == 2) q.push({ i, j });
		}
	}
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
			if (labCopy[nx][ny] != 0) continue;
			labCopy[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}
	CntSafe(labCopy);
}

void SetWall()
{
	for (int i = 0; i < emp.size() - 2; i++)
	{
		for (int j = i + 1; j < emp.size() - 1; j++)
		{
			for (int k = j + 1; k < emp.size(); k++)
			{
				int labCopy[8][8];
				for (int x = 0; x < n; x++)
				{
					for (int y = 0; y < m; y++)
					{
						labCopy[x][y] = lab[x][y];
					}
				}
				labCopy[emp[i].x][emp[i].y] = 1;
				labCopy[emp[j].x][emp[j].y] = 1;
				labCopy[emp[k].x][emp[k].y] = 1;
				setVirus(labCopy);
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 0) emp.push_back({ i, j });
		}
	}
	SetWall();
	cout << answer;
	return 0;
}
