#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n;
bool maze[100][100];
int cnt[100][100];
bool check[100][100];

void search_nm()
{
	queue<pair<int, int> > q;
	check[0][0] = true;
	cnt[0][0] = 1;
	q.push({0, 0});
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int dist = cnt[x][y];
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(0<=nx && nx<n) || !(0<=ny && ny<m) || check[nx][ny])
				continue;
			else if(maze[nx][ny])
			{
				check[nx][ny] = true;
				q.push({nx, ny});
				cnt[nx][ny] = dist+1;
			}
		}
	}
	
}

void mk_num(int index, string num)
{
	int size = num.size();
	for(int i=0; i<size; i++)
	{
		maze[index][i] = num[i] - '0';
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
		string num;
		cin >> num;
		mk_num(i, num);
	}
	
	search_nm();
	
	cout << cnt[n-1][m-1];
	return 0;
}
