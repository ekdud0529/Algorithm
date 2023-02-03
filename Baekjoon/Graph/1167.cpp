#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int x;
	int cost;
};

int n;
vector<Node> graph[100001];
int visited[100001];
long long maxDist = 0;
int maxNode;

void dfs(int parent, int cost)
{
	if (maxDist < cost)
	{
		maxDist = cost;
		maxNode = parent;
	}
	for (int i = 0; i<graph[parent].size(); i++)
	{
		if (visited[graph[parent][i].x]) continue;
		visited[graph[parent][i].x] = true;
		dfs(graph[parent][i].x, cost + graph[parent][i].cost);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, cost;
		cin >> x;
		while (1)
		{
			cin >> y;
			if (y == -1) break;
			cin >> cost;
			graph[x].push_back({ y, cost });
			graph[y].push_back({ x, cost });
		}
	}
	visited[1] = true;
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	visited[maxNode] = true;
	dfs(maxNode, 0);
	cout << maxDist;
	return 0;
}
