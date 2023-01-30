#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
bool truth[51];
vector<int> party[50];
vector<int> lie[51];

bool CheckTruth(int index)
{
	for (int i = 0; i < party[index].size(); i++)
	{
		if (truth[party[index][i]])
			return (true);
	}
	return (false);
}

void ReTruth(int index)
{
	for (int i = 0; i < party[index].size(); i++)
	{
		if (truth[party[index][i]]) continue;
		truth[party[index][i]] = true;
		for (int j = 0; j < lie[party[index][i]].size(); j++)
		{
			if (index == lie[party[index][i]][j]) continue;
			ReTruth(lie[party[index][i]][j]);
		}
	}
}

void getMax(int index)
{
	if (index == m) return;
	if (CheckTruth(index))
	{
		ReTruth(index);
	}
	else
	{
		for (int i = 0; i < party[index].size(); i++)
		{
			lie[party[index][i]].push_back(index);
		}
	}
}

int main()
{
	int answer = 0;

	cin >> n >> m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		truth[num] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		while (p--)
		{
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}
	for (int i = 0; i < m; i++)
	{
		getMax(i);
	}
	for (int i = 0; i < m; i++)
	{
		if (!CheckTruth(i)) answer++;
	}
	cout << answer;
	return 0;
}
