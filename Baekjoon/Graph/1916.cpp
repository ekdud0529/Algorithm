#include <bits/stdc++.h>
using namespace std;

int INF = 100000001;
int n, m, x, y;
vector<pair<int, int> > graph[1001];
int dist[1001];

void dijkstra()
{
	dist[x] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, x});
	
	while(!pq.empty())
	{
		int index = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		
		if(dist[index] < d) continue;
		for(int i=0; i<graph[index].size(); i++)
		{
			int next = graph[index][i].first;
			int nextD = graph[index][i].second + d;
			
			if(nextD < dist[next])
			{
				dist[next] = nextD;
				pq.push({(-nextD), next});
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({e, w});
	}
	cin >> x >> y;
	
	for(int i=1; i<=n; i++)
		dist[i] = INF;
		
	dijkstra();

	cout << dist[y];
	return 0;
}
