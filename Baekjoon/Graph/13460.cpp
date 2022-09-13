#include <iostream>
#include <utility>
using namespace std;

int		n, m;
char	map[10][10];
int		dx[4] = { 0, 0, -1, 1 };
int		dy[4] = { 1, -1, 0, 0 };
int		move_cnt = 1000000000;

void	bfs(pair<int, int> red, pair<int, int> blue, int cnt, int dir)
{
	if (cnt > 10) return;
	int		rx = red.first;
	int		ry = red.second;
	int		bx = blue.first;
	int		by = blue.second;
	bool	r_check = false;
	bool	b_check = false;

	while (1)
	{
		rx += dx[dir];
		ry += dy[dir];
		if (map[rx][ry] == '#')
			break;
		if (map[rx][ry] == 'O')
		{
			r_check = true;
			break;
		}
	}
	rx -= dx[dir];
	ry -= dy[dir];
	while (1)
	{
		bx += dx[dir];
		by += dy[dir];
		if (map[bx][by] == '#')
			break;
		if (map[bx][by] == 'O')
		{
			b_check = true;
			break;
		}
	}
	bx -= dx[dir];
	by -= dy[dir];
	if (b_check)
		return;
	if (r_check)
	{
		if (cnt < move_cnt)
			move_cnt = cnt;
		return ;
	}
	if ((rx == bx) && (ry == by))
	{
		int r_move = abs(rx - red.first) + abs(ry - red.second);
		int b_move = abs(bx - blue.first) + abs(by - blue.second);
		if (r_move > b_move)
		{
			rx -= dx[dir];
			ry -= dy[dir];
		}
		else
		{
			bx -= dx[dir];
			by -= dy[dir];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		bfs({ rx, ry }, { bx, by }, cnt + 1, i);
	}
}

int	main(void)
{
	pair<int, int> red;
	pair<int, int> blue;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				red.first = i;
				red.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B')
			{
				blue.first = i;
				blue.second = j;
				map[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		bfs(red, blue, 1, i);
	}

	if (move_cnt <= 10)
		cout << move_cnt;
	else
		cout << "-1";
	return (0);
}
