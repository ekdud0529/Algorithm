#include <bits/stdc++.h>
using namespace std;

bool check[15];
int t[15];
int p[15];
int sum_max = 0;
int n;

void what_max(int sum)
{
	if(sum > sum_max)
	{
		sum_max = sum;
	}
}

void get_max(int index, int sum)
{
	if(index >= n)
	{
		what_max(sum);
		return ;
	}

	for(int i=index; i<n; i++)
	{
		if(i+t[i] > n)
		{
			what_max(sum);
			continue;
		}
		sum += p[i];
		get_max(i+t[i], sum);
		sum -= p[i];
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
		cin >> t[i] >> p[i];
	}

	get_max(0, 0);
	cout << sum_max;
	return 0;
}
