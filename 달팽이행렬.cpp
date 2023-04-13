#include <iostream>
using namespace std;

int arr[10][10];

int	main(void)
{
	int n;
	int num = 1;
	int x = 0;
	int y = 0;
	int direct = 0;
	int cnt;

	cin >> n;
	cnt = n;
	for (int i = 0; i < n * 2 - 1; i++)
	{
		switch (direct % 4)
		{
			case 0:
				for (int j = 0; j < cnt; j++)
				{
					arr[x][y] = num;
					num++;
					y++;
				}
				y--;
				x++;
				cnt--;
				break;
			case 1:
				for (int j = 0; j < cnt; j++)
				{
					arr[x][y] = num;
					x++;
					num++;
				}
				x--;
				y--;
				break;
			case 2:
				for (int j = 0; j < cnt; j++)
				{
					arr[x][y] = num;
					num++;
					y--;
				}
				y++;
				x--;
				cnt--;
				break;
			case 3:
				for (int j = 0; j < cnt; j++)
				{
					arr[x][y] = num;
					num++;
					x--;
				}
				x++;
				y++;
				break;
		}
		direct += 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "	";
		}
		cout << "\n";
	}
	return (0);
}
