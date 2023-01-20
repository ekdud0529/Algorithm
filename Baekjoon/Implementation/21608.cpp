#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Seat {
	int x, y;
	int like;
	int empty;
};

int n;
int student[400][5];
int classroom[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
Seat studentSeat[400];

vector<Seat> GetSeatData(int index)
{
	vector<Seat> seat;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (classroom[i][j] != 0) continue;
			Seat s;
			s.x = i;
			s.y = j;
			s.like = 0;
			s.empty = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
				if (classroom[nx][ny] == 0) s.empty++;
				else
				{
					for (int l = 1; l < 5; l++)
					{
						if (classroom[nx][ny] == student[index][l])
						{
							s.like++;
							break;
						}
					}
				}
			}
			seat.push_back(s);
		}
	}
	return (seat);
}

bool Cmp(const Seat &a, const Seat &b)
{
	if (a.like == b.like)
	{
		if (a.empty == b.empty)
		{
			if (a.x == b.x)
			{
				return (a.y < b.y);
			}
			else return (a.x < b.x);
		}
		else
			return (a.empty > b.empty);
	}
	return (a.like > b.like);
}

void GetSeat()
{
	for (int i = 0; i < n * n; i++)
	{
		vector<Seat> seat;
		seat = GetSeatData(i);
		sort(seat.begin(), seat.end(), Cmp);
		classroom[seat[0].x][seat[0].y] = student[i][0];
		studentSeat[i].x = seat[0].x;
		studentSeat[i].y = seat[0].y;
	}
}

int GetSatisf()
{
	int satisf = 0;

	for (int i = 0; i < n * n; i++)
	{
		int x = studentSeat[i].x;
		int y = studentSeat[i].y;
		int like = 0;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
			for (int l = 1; l < 5; l++)
			{
				if (student[i][l] == classroom[nx][ny])
				{
					like++;
				}
			}
		}
		if (like == 1) satisf += 1;
		else if (like == 2) satisf += 10;
		else if (like == 3) satisf += 100;
		else if (like == 4) satisf += 1000;
	}
	return (satisf);
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n * n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> student[i][j];
		}
	}
	GetSeat();
	cout << GetSatisf();
	return 0;
}
