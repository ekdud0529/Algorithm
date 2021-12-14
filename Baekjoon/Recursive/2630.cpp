#include <bits/stdc++.h>
using namespace std;

int n;
int paper[128][128];
int w_cnt = 0, b_cnt = 0;

void get_cnt(int x, int y, int size)
{
	if(size == 1)
	{
		if(paper[x][y]) b_cnt++;
		else w_cnt++;
		return ;
	}
	
	int blue_cnt = 0;

	for(int i=x; i<x+size; i++)
	{
		for(int k=y; k<y+size; k++)
		{
			if(paper[i][k]) blue_cnt++;
		}
	}
	
	if(blue_cnt == 0) w_cnt++;
	else if(size*size == blue_cnt) b_cnt++;
	else
	{
		get_cnt(x, y, size/2);
		get_cnt(x+(size/2), y, size/2);
		get_cnt(x, y+(size/2), size/2);
		get_cnt(x+(size/2), y+(size/2), size/2);
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
			cin >> paper[i][k];
		}
	}
	
	get_cnt(0, 0, n);
	
	cout << w_cnt << "\n" << b_cnt;
	
	return 0;
}
