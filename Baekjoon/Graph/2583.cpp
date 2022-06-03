#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
bool visited[100][100];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void setRectangle(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i < x2; i++)
	{
		for (int j = y1; j < y2; j++)
		{
			visited[i][j] = true;
		}
	}
}

int cntRemain(int x, int y)
{
	int range = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (visited[nx][ny])
			continue;
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		visited[nx][ny] = true;
		range += cntRemain(nx, ny);
	}
	return (range);
}

int main()
{
	vector<int> range;
	int cnt = 0;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		setRectangle(x1, y1, x2, y2);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			cnt++;
			visited[i][j] = true;
			range.push_back(cntRemain(i, j));
		}
	}
	cout << cnt << "\n";
	sort(range.begin(), range.end());
	for (int r : range)
		cout << r << " ";
	return 0;
}
