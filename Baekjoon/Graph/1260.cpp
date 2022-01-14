#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool d_visited[1001];
bool b_visited[1001];

void dfs(int start)
{
	sort(graph[start].begin(), graph[start].end());
	cout << start << " ";
	d_visited[start] = true;
	for(int i=0; i<graph[start].size(); i++)
	{
		if(!d_visited[graph[start][i]])
			dfs(graph[start][i]);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	b_visited[start] = true;
	
	while(!q.empty())
	{
		int num = q.front();
		cout << num << " ";
		q.pop();
		
		for(int i=0; i<graph[num].size(); i++)
		{
			if(!b_visited[graph[num][i]])
			{
				q.push(graph[num][i]);
				b_visited[graph[num][i]] = true;
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> v;
	
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(v);
	cout << "\n";
	bfs(v);
	
	return 0;
}
