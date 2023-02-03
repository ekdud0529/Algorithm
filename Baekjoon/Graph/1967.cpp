#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int x;
	int cost;
};

int n;
vector<Node> graph[10001];
int visited[10001];
int maxLine = 0;

void dfs(int parent, int cost)
{
	if (maxLine < cost) maxLine = cost;
	for (int i = 0; i<graph[parent].size(); i++)
	{
		if (visited[graph[parent][i].x]) continue;
		visited[graph[parent][i].x] = true;
		dfs(graph[parent][i].x, cost + graph[parent][i].cost);
		visited[graph[parent][i].x] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		graph[x].push_back({ y, cost });
		graph[y].push_back({ x, cost });
	}
	for (int i = 1; i <= n; i++)
	{
		visited[i] = true;
		dfs(i, 0);
		visited[i] = false;
	}
	cout << maxLine;
	return 0;
}
