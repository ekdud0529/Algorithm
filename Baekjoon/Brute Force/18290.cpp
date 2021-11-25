#include <bits/stdc++.h>
using namespace std;

int table[10][10];
bool check[10][10];
int sum_max = -90000;
int n, m, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void 	what_max(int sum);
int 	side_check(int x, int y);

void get_max(int cnt, int sum)
{
	if(k == cnt)
	{
		what_max(sum);
		return ;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(!check[i][j] && side_check(i, j)) 
			{
				check[i][j] = true;
				get_max(cnt+1, sum+table[i][j]);
				check[i][j] = false;
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> table[i][j];
		}
	}
	
	get_max(0, 0);

	cout << sum_max;
	
	return 0;
}

int side_check(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}
		else if(check[nx][ny])
		{
			return 0;
		}
	}
	return 1;
}

void what_max(int sum)
{
	if(sum > sum_max)
	{
		sum_max = sum;
	}
}
