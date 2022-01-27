#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool check[100][100];
int n;

int bfs(char p[][100])
{
	queue<pair<int, int> > q;
	int area = 0;
	
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
			check[i][k] = false;
	}

	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			if(check[i][k]) continue;
			
			q.push({i, k});
			check[i][k] = true;
			while(!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for(int j=0; j<4; j++)
				{
					int nx = x + dx[j];
					int ny = y + dy[j];
					
					if(!(0<=nx && nx<n) || !(0<=ny && ny<n) || check[nx][ny]) 
						continue;
					if(p[i][k] == p[nx][ny])
					{
						check[nx][ny] = true;
						q.push({nx, ny});
					}
				}
			}
			area++;
		}
	}
	return area;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char paint_rg[100][100];
	char paint[100][100];

	cin >> n;
	
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
		{
			cin >> paint[i][k];
			if(paint[i][k] == 'G') paint_rg[i][k] = 'R';
			else paint_rg[i][k] = paint[i][k];
		}
			
	
	int cnt_rg = bfs(paint_rg);
	int cnt = bfs(paint);
	
	cout << cnt << " " << cnt_rg;
	return 0;
}
