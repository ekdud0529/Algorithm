#include <iostream>
#include <utility>
using namespace std;

struct Fish {
	int x;
	int y;
	int num;
	int direct;
};

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
Fish grid[4][4];
Fish fish[17];
Fish shark;
int answer = 0;

void Input()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> grid[i][j].num >> grid[i][j].direct;
			grid[i][j].direct -= 1;
			fish[grid[i][j].num].x = i;
			fish[grid[i][j].num].y = j;
			fish[grid[i][j].num].direct = grid[i][j].direct;
			fish[grid[i][j].num].num = grid[i][j].num;
		}
	}
}

void SwapFish(int now, int moveX, int moveY)
{
	Fish tmp = fish[now];
	int num = grid[moveX][moveY].num;

	grid[fish[now].x][fish[now].y] = grid[moveX][moveY];
	grid[moveX][moveY] = tmp;
	fish[now].x = moveX;
	fish[now].y = moveY;
	if (num != 0)
	{
		fish[num].x = tmp.x;
		fish[num].y = tmp.y;
	}
}

void MoveFish()
{
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].num == -1)
			continue;
		for (int j = 0; j < 8; j++)
		{
			int nx = fish[i].x + dx[(fish[i].direct + j) % 8];
			int ny = fish[i].y + dy[(fish[i].direct + j) % 8];
			if (0 > nx || nx >= 4 || 0 > ny || ny >= 4)
				continue;
			if (grid[nx][ny].num == -1)
				continue;
			SwapFish(i, nx, ny);
			fish[i].direct = (fish[i].direct + j) % 8;
			grid[fish[i].x][fish[i].y].direct = fish[i].direct;
			break;
		}
		
	}
}

void SharkMove(int x, int y)
{
	grid[shark.x][shark.y].num = 0;
	shark.x = x;
	shark.y = y;
	shark.direct = grid[x][y].direct;
	fish[grid[x][y].num].num = -1;
	grid[x][y].num = -1;
}

void SharkEat(int ans)
{
	int nx = shark.x;
	int ny = shark.y;
	Fish gridCpy[4][4];
	Fish fishCpy[17];
	Fish sharkCpy;

	if (ans > answer)
		answer = ans;
	MoveFish();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gridCpy[i][j] = grid[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) fishCpy[i] = fish[i];
	sharkCpy = shark;
	for (int i = 0; i < 4; i++)
	{
		nx = nx + dx[shark.direct];
		ny = ny + dy[shark.direct];
		if (0 > nx || nx >= 4 || 0 > ny || ny >= 4)
			break;
		if (grid[nx][ny].num == 0)
			continue;
		int num = grid[nx][ny].num;
		SharkMove(nx, ny);
		SharkEat(ans + num);
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				grid[k][j] = gridCpy[k][j];
			}
		}
		for (int j = 1; j <= 16; j++)
		{
			fish[j] = fishCpy[j];
		}
		shark = sharkCpy;
	}
}

int	main(void)
{
	Input();
	shark.direct = grid[0][0].direct;
	answer += grid[0][0].num;
	fish[grid[0][0].num].num = -1;
	grid[0][0].num = -1;
	SharkEat(answer);
	cout << answer;
	return (0);
}
