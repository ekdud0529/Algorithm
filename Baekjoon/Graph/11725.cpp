#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int parent[100001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int num = q.front();
		q.pop();
		int size = graph[num].size();
		for(int i=0; i<size; i++)
		{
			if(!parent[graph[num][i]])
			{
				parent[graph[num][i]] = num;
				q.push(graph[num][i]);
			}
		}
	}
		
	for(int i=2; i<=n; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}
