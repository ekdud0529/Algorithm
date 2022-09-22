#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int tmpN;
int tree[1024 * 1024];
vector<pair<int, int>> player;

bool CmpPower(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second < b.second)
		return (true);
	else
		return (false);
}

bool CmpIndex(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first < b.first)
		return (true);
	else
		return (false);
}

int getSum(int a, int b)
{
	int sum = 0;

	a = tmpN + a - 1;
	b = tmpN + b - 1;
	while (a <= b)
	{
		if ((a & 1) == 1)
			sum += tree[a];
		if ((b & 1) == 0) sum += tree[b];
		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}
	return (sum);
}

void Update(int index)
{
	index = index + tmpN - 1;
	while (index)
	{
		tree[index] += 1;
		index = index >> 1;
	}
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int power;

	cin >> n;
	for (tmpN = 1; tmpN < n; tmpN *= 2);
	for (int i = 0; i < n; i++)
	{
		cin >> power;
		player.push_back({ i, power });
	}
	sort(player.begin(), player.end(), CmpPower);
	for (int i = 0; i < n; i++)
	{
		player[i].second = i + 1;
	}
	sort(player.begin(), player.end(), CmpIndex);
	for (int i = 0; i < n; i++)
	{
		cout << player[i].first + 1 - getSum(1, player[i].second) << "\n";
		Update(player[i].second);
	}
	return (0);
}
