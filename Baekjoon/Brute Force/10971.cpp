#include <bits/stdc++.h>
using namespace std;

bool ch_city[10];
int cost[10][10];
int n, sum_min = 10000001;

void get_min(int index, int cnt, int sum, int start)
{
	if(cnt == n)
	{
		if(cost[index][start])
		{
			sum += cost[index][start];
			if(sum < sum_min)
			{
				sum_min = sum;
			}
		}
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if(ch_city[i] || !cost[index][i]) continue;
		ch_city[i] = true;
		get_min(i, cnt + 1, sum+cost[index][i], start);
		ch_city[i] = false;
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
			cin >> cost[i][k];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		ch_city[i] = true;
		get_min(i, 1, 0, i);
		ch_city[i] = false;
	}
	
	cout << sum_min;
	
	return 0;
}
