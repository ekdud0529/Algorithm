#include <iostream>
using namespace std;

int		n, m;
int		board[50][50];
bool	visited[50][50];
int		cache[50][50];
int		dy[4] = { 0, 0, 1, -1 };
int		dx[4] = { 1, -1, 0, 0 };
int		cycle = 0;

int rec(int x, int y);
int	main(void)
{
	string	num;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 0; j < num.size(); j++)
		{
			if (num[j] == 'H')
				board[i][j] = -1;
			else
				board[i][j] = num[j] - '0';
		}
	}
	cout << rec(0, 0);
	return (0);
}

int	rec(int x, int y)
{
	if (board[x][y] == -1 || x < 0 || x >= n || y < 0 || y >= m || cycle == -1)
		return (0);
	if (visited[x][y] == true)
	{
		cycle = -1;
		return (-1);
	}
	if (cache[x][y] != 0)
		return (cache[x][y]);
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int move = rec(x + (dx[i] * board[x][y]), y + (dy[i] * board[x][y])) + 1;
		if (cache[x][y] < move) cache[x][y] = move;
	}
	visited[x][y] = false;
	if (cycle == -1)
		return (-1);
	return (cache[x][y]);
}
