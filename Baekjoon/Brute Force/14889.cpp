#include <bits/stdc++.h>
using namespace std;

int		n;
int		min_ability = 2000;
int		member[20][20];
bool	check[20];

int get_ability(bool ch)
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int k=i+1; k<n; k++)
		{
			if(check[i] == ch && check[k] == ch)
			{
				sum += (member[i][k] + member[k][i]);
			}
		}
	}
	return sum;
}

void get_min_ability(int cnt, int index)
{
	if(cnt == n/2)
	{
		int sum = get_ability(true);
		int other_sum = get_ability(false);
		if(min_ability > abs(sum - other_sum))
		{
			min_ability = abs(sum - other_sum);
		}
		return ;
	}

	for(int i=index; i<n; i++)
	{
		if(check[i]) continue;
		check[i] = true;
		get_min_ability(cnt + 1, i);
		check[i] = false;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			cin >> member[i][k];
		}
	}

	get_min_ability(0, 0);
	cout << min_ability;
	return 0;
}
