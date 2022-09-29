#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visited[100001];

int main(int argc, char** argv) {
	int a, b, n, m;
	int min_move = 1000000;
	cin >> a >> b >> n >> m;

	int move[6] = { 1, a, b, -1, -a, -b};

	queue<pair<int, int> > pos;
	visited[n] = true;
	pos.push({ n, 0 });

	while (!pos.empty())
	{
		int dong = pos.front().first;
		int	cnt = pos.front().second;
		visited[dong] = true;
		pos.pop();

		if (dong == m)
		{
			cout << cnt;
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			int mv = dong + move[i];
			if (mv < 0 || mv > 100000) continue;
			if (visited[mv]) continue;
			visited[mv] = true;
			pos.push({ mv, cnt + 1 });
		}
		for (int i = 1; i <= 2; i++)
		{
			int mv = dong * move[i];
			if (mv < 0 || mv > 100000) continue;
			if (visited[mv]) continue;
			visited[mv] = true;
			pos.push({ mv, cnt + 1 });
		}
	}
	return 0;
}
