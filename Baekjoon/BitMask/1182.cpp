#include <bits/stdc++.h>
using namespace std;

int n, s;
int num[20];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> s;
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
	}
	int cnt = 0;
	for(int i=1; i<(1 << n); i++)
	{
		int sum = 0;
		for(int k=0; k<n; k++)
		{
			if(i & (1 << k))
			{
				sum += num[k];
			}
		}
		if(sum == s) cnt++;
	}
	cout << cnt;
	return 0;
}
