#include <iostream>
using namespace std;

int n, m, r, c, d;
int answer = 0;
int room[51][51];
// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Cleaning()
{
	int dir = d;
	int repet = 0;

	while(repet < 4)
	{
		dir = (dir + 3) % 4;
		int nx = r + dx[dir];
		int ny = c + dy[dir];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && room[nx][ny] == 0)
		{
			room[nx][ny] = 2;
			answer++;
			r = nx;
			c = ny;
			d = dir;
			repet = 0;
		}
		else repet++;
	}
	r = r + (dx[d] * -1);
	c = c + (dy[d] * -1);
	if (r < 0 || r >= n || c < 0 || c >= m || room[r][c] == 1)
		return ;
	Cleaning();
}

int main(void)
{
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}
	room[r][c] = 2;
	answer++;
	Cleaning();
	cout << answer;
	return 0;
}
