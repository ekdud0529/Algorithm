#include <bits/stdc++.h>
using namespace std;

int polyomino[500][500];
int n, m;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
bool check[500][500];
int sum_max = 0;

void max(int sum)
{
	if(sum > sum_max)
	{
		sum_max = sum;
	}
}

void get_max(int cnt, int sum, int a, int b)
{
	if(cnt == 4)
	{
		max(sum);
		return ;
	}

	for(int i=0; i<4; i++)
	{
		int nx = a + x[i];
		int ny = b + y[i];

		if(!(0 <= nx && nx < n) || !(0 <= ny && ny < m) || check[nx][ny])
			continue;
		check[a][b] = true;
		get_max(cnt+1, sum+polyomino[nx][ny], nx, ny);
		check[nx][ny] = false;
	}
}

void check_a(int x, int y)
{
	int sum = 0;
	// ㅏ
	if(2 <= x+2 && x+2 < n && 1 <= y+1 && y+1 < m)
	{
		sum = polyomino[x][y] + polyomino[x+1][y] + polyomino[x+2][y] + polyomino[x+1][y+1];
		max(sum);
	}
	// ㅓ
	if(1 <= x+2 && x+2 < n && 0 <= y-1 && y-1 < m)
	{
		sum = polyomino[x][y] + polyomino[x+1][y] + polyomino[x+2][y] + polyomino[x+1][y-1];
		max(sum);
	}
	// ㅗ
	if(0 <= x-1 && x-1 < n && 2 <= y+2 && y+2 < m)
	{
		sum = polyomino[x][y] + polyomino[x][y+1] + polyomino[x][y+2] + polyomino[x-1][y+1];
		max(sum);
	}	
	// ㅜ
	if(1<=x+1 && x+1 < n && 2 <= y+2 && y+2 < m)
	{
		sum = polyomino[x][y] + polyomino[x][y+1] + polyomino[x][y+2] + polyomino[x+1][y+1];
		max(sum);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<m; k++)
		{
			cin >> polyomino[i][k];
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int k=0; k<m; k++)
		{
			check[i][k] = true;
			get_max(1, polyomino[i][k], i, k);
			check[i][k] = false;

			check_a(i, k);
		}
	}
	cout << sum_max;
	return 0;
}
