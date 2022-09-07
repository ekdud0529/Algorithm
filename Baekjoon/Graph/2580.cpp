#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int puzzle[9][9];
vector<pair<int,int>>	blank;

bool checkBlank(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (puzzle[i][j] == 0)
				return (false);
		}
	}
	return (true);
}

bool	searchNum(int x, int y, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (puzzle[x][i] == num)
			return (false);
	}
	for (int i = 0; i < 9; i++)
	{
		if (puzzle[i][y] == num)
			return (false);
	}
	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
	{
		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
		{
			if (puzzle[i][j] == num)
				return (false);
		}
	}
	return (true);
}

void	sudoku(int index)
{
	if (index == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << puzzle[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	for (int i = index; i < blank.size(); i++)
	{
		int x = blank[i].first;
		int y = blank[i].second;
		for (int j = 1; j <= 9; j++)
		{
			if (searchNum(x, y, j) == true)
			{
				puzzle[x][y] = j;
				sudoku(i + 1);
				puzzle[x][y] = 0;
			}
			if (j == 9) return ;
		}
	}
}

int	main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> puzzle[i][j];
			if (puzzle[i][j] == 0)
				blank.push_back({ i, j });
		}
	}
	sudoku(0);
	return (0);
}
