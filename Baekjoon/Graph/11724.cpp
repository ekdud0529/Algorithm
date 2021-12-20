#include <bits/stdc++.h>
using namespace std;

int n, m;
bool check[1001];
bool graph[1001][1001];
vector<int> g[1001];

void get_link(int index)
{
	if(g[index].size() == 0) return ;
	
	int size = g[index].size();
	for(int i=0; i<size; i++)
	{
		if(check[g[index][i]]) continue;
		check[g[index][i]] = true;
		get_link(g[index][i]);
	}
	
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		if(check[i]) continue;
		cnt++;
		check[i] = true;
		get_link(i);
	}
	
	cout << cnt;
	return 0;
}
