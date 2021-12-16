#include <bits/stdc++.h>
using namespace std;

int n, m;
bool computer[101][101];
bool virus[101];
int cnt = 0;

void get_cnt(int index)
{
	for(int i=1; i<=n; i++)
	{
		if(virus[i]) continue;
		if(computer[index][i])
		{
			virus[i] = true;
			cnt++;
			get_cnt(i);
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++)
	{
		int ln1, ln2;
		cin >> ln1 >> ln2;
		computer[ln1][ln2] = true;
		computer[ln2][ln1] = true;
	}
	
	virus[1] = true;
	get_cnt(1);
	
	cout << cnt;
	return 0;
}
