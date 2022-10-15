#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int t[501];
int ans[501];
int indegree[501];
vector<int> list[501];
queue<int> zero;

void findZero()
{
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			indegree[i] = -1;
			zero.push(i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		t[i] = x;
		while (cin >> x)
		{
			if (x == -1) break;
			indegree[i]++;
			list[x].push_back(i);
		}
	}
	findZero();
	while (!zero.empty())
	{
		int index = zero.front();
		zero.pop();
		for (int a : list[index])
		{
			if(ans[a] < ans[index] + t[index])
				ans[a] = ans[index] + t[index];
			indegree[a]--;
		}
		findZero();
	}
	for (int i = 1; i <= n; i++)
	{
		cout << t[i] + ans[i] << "\n";
	}
	return (0);
}
