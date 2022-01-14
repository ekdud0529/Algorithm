#include <bits/stdc++.h>
using namespace std;

int paper[2187][2187];
int cnt[3];

bool check(int x, int y, int len)
{
	int num = paper[x][y];
	
	for(int i=x; i<x+len; i++)
	{
		for(int k=y; k<y+len; k++)
		{
			if(paper[i][k] != num)
			{
				return false;
			}
		}
	}
	return true;
}

void get_paper(int x, int y, int len)
{
	bool ch = check(x, y, len);
	
	if(ch)
	{
		if(paper[x][y] == -1) cnt[0] += 1;
		else if(paper[x][y] == 0) cnt[1] += 1;
		else if(paper[x][y] == 1) cnt[2] += 1;
		return ;
	}
	else
	{
		get_paper(x, y, len/3);
		get_paper(x, y+len/3, len/3);
		get_paper(x, y+(len/3*2), len/3);
		get_paper(x+len/3, y, len/3);
		get_paper(x+len/3, y+len/3, len/3);
		get_paper(x+len/3, y+(len/3*2), len/3);
		get_paper(x+(len/3*2), y, len/3);
		get_paper(x+(len/3*2), y+len/3, len/3);
		get_paper(x+(len/3*2), y+(len/3*2), len/3);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			cin >> paper[i][k];
		}
	}
	
	get_paper(0, 0, n);
	
	for(int i=0; i<3; i++)
	{
		cout << cnt[i] << "\n";
	}
	
	return 0;
}
