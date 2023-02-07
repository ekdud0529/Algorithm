#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int visit[100001][2];

int Move(int pos, int mv)
{
	if (mv == 1)
		return (pos + 1);
	else if (mv == 2)
		return (pos - 1);
	return (pos * 2);
}

void bfs(int n, int k)
{
	queue<int> q;

	q.push(n);
	visit[n][0] = 0;
	visit[n][1] = 1;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		for (int i = 1; i <= 3; i++)
		{
			int mvPos = Move(pos, i);
			if (0 > mvPos || mvPos > 100000) continue;
			if (visit[mvPos][0] == -1)
			{
				visit[mvPos][0] = visit[pos][0] + 1;
				visit[mvPos][1] = visit[pos][1];
				q.push(mvPos);
			}
			else if (visit[mvPos][0] == (visit[pos][0] + 1))
			{
				visit[mvPos][1] += visit[pos][1];
			}
		}
	}
}

int main()
{
	int n, k;

	cin >> n >> k;
	for (int i = 0; i <= 100000; i++)
	{
		visit[i][0] = -1;
	}
	bfs(n, k);
	cout << visit[k][0] << "\n" << visit[k][1];
	return 0;
}
