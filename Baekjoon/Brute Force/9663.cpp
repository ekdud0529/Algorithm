#include <bits/stdc++.h>
using namespace std;

bool queen[15][15];
int cnt = 0;
int n;

void reset()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			queen[i][j] = false;
		}
	}
}

bool check_pos(int x, int y)
{
	int nx = x;
	int ny = y;
	//좌
	while(--ny >= 0)
	{
		if(queen[nx][ny])
			return false;
	}
	//좌하대각
	nx = x;
	ny = y;	
	while((--nx >= 0) && (--ny >= 0))
	{
		if(queen[nx][ny])
			return false;
	}
	nx = x;
	ny = y;
	while((++nx < n) && (++ny < n))
	{
		if(queen[nx][ny])
			return false;
	}
	//좌상대각
	nx = x;
	ny = y;
	while((++nx < n) && (--ny >= 0))
	{
		if(queen[nx][ny])
			return false;
	}
	nx = x;
	ny = y;
	while((--nx >= 0) && (++ny < n))
	{
		if(queen[nx][ny])
			return false;
	}
	
	return true;
}

void mk_pos(int x, int y)
{
	bool check = check_pos(x, y);
	if(check)
	{
		if(y+1 == n)
		{
			cnt++;
			return ;
		}
		
		queen[x][y] = true;
		for(int i=0; i<n; i++)
		{
			mk_pos(i, y+1);
		}
		queen[x][y] = false;
	}
	else
		return ;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		mk_pos(i, 0);
		reset();
	}
	cout << cnt;
	return 0;
}
