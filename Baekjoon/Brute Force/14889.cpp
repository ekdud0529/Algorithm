#include <bits/stdc++.h>
using namespace std;

int n, sum_min = 50000;
int ability[20][20];
bool member[20];

int get_sum()
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			if(i == k) continue;
			if(member[i] && member[k])
			{
				sum += ability[i][k];
				sum += ability[k][k];
			}
		}
	}
	return sum;
}

int get_other_sum()
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			if(i == k) continue;
			if(!member[i] && !member[k])
			{
				sum += ability[i][k];
				sum += ability[k][k];
			}
		}
	}
	return sum;
}

void get_min(int cnt, int index)
{
	if(cnt == n/2)
	{
		int sum = get_sum();
		int other_sum = get_other_sum();
		int minus = (sum > other_sum)? sum-other_sum : other_sum-sum;
		if(minus < sum_min)
		{
			sum_min = minus;
		}
	}

	for(int i=index; i<n; i++)
	{
		if(member[i]) continue;
		member[i] = true;
		get_min(cnt+1, i);
		member[i] = false;
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
			cin >> ability[i][k];
		}
	}

	get_min(0, 0);
	cout << sum_min;
	return 0;
}
