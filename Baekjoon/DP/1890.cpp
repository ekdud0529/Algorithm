#include <bits/stdc++.h>
using namespace std;

int game[100][100];
long long dp[100][100];
bool visited[100][100];

long long dfs(int n, int x, int y)
{
	if((x == n-1) && (y == n-1)) 
		return (1);
		
	if(visited[x][y])
		return dp[x][y];

	visited[x][y] = true;
	int nx = x + game[x][y];
	int ny = y + game[x][y];
	
	
	if(nx < n)
		dp[x][y] += dfs(n, nx, y);
	if(ny < n)
		dp[x][y] += dfs(n, x, ny);
	
	return dp[x][y];
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> game[i][j];
		}
	}
	cout << dfs(n, 0, 0);
	return 0;
}
