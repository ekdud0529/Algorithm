#include <bits/stdc++.h>
using namespace std;

int INF = 200000;
vector<pair<int, int> > graph[20001];
int dist[20001];
int v, e;

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, start});
	
	while(!pq.empty())
	{
		int current = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		
		if(dist[current] < d) continue;
		for(int i=0; i<graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			int nextD = d + graph[current][i].second;
			
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
	
	int start;
	cin >> v >> e >> start;
	
	for(int i=0; i<e; i++)
	{
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		graph[n1].push_back({n2, w});
	}
	for(int i=1; i<=v; i++)
		dist[i] = INF;

	dijkstra(start);
	
	for(int i=1; i<=v; i++)
	{
		if(dist[i]== INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}
