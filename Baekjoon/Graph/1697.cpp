#include <bits/stdc++.h>
using namespace std;

bool pos[100001];
int n, k;

int get_move(int n)
{
	pos[n] = true;
	queue<pair<int, int> > q;
	q.push({n, 0});
	
	if(n == k) return 0;
	
	while(q.size())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(!(x+1 > 100000 || x+1 < 0 || pos[x+1]))
		{
			if(x+1 == k)
			{
				n = cnt+1;
				break;
			}
			pos[x+1] = true;
			q.push({x+1, cnt+1});
		}
		if(!(x-1 > 100000 || x-1 < 0 || pos[x-1]))
		{
			if(x-1 == k)
			{
				n = cnt+1;
				break;
			}
			pos[x-1] = true;
			q.push({x-1, cnt+1});
		}
		if(!(x*2 > 100000 || x*2 < 0 || pos[x*2]))
		{
			if(x*2 == k)
			{
				n = cnt+1;
				break;
			}
			pos[x*2] = true;
			q.push({x*2, cnt+1});
		}
	}
	return n;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	int move = get_move(n);
	cout << move;
	return 0;
}
