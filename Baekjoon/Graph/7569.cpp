#include <bits/stdc++.h>
using namespace std;

int box[100][100][100];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int m, n, h;
int day = 0;

bool check_ripe()
{
	bool check = false;
	
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<m; k++)
			{
				if(box[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

void bfs()
{
	if(check_ripe()) return ;
	queue<pair<int, pair<int, int>> > q;
	
	for(int i=0; i<h; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<m; k++)
			{
				if(box[i][j][k] == 1)
					q.push({i, {j, k}});
			}
			
	while(!q.empty())
	{
		if(check_ripe()) return ;
		
		int cnt = q.size();
		for(int i=0; i<cnt; i++)
		{
			int z = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			
			for(int k=0; k<6; k++)
			{
				int nz = z + dz[k];
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if((0 <= nz && nz < h) && (0 <= nx && nx < n)
				&& (0 <= ny && ny < m) && box[nz][nx][ny] == 0)
				{
					q.push({nz, {nx, ny}});
					box[nz][nx][ny] = 1;
				}
			}
			q.pop();
		}
		day++;
	}
	
	if(!check_ripe()) day = -1;
 }

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n >> h;
	
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<m; k++)
			{
				cin >> box[i][j][k];
			}
		}
	}
	
	bfs();
	
	cout << day;
	
	return 0;
}
