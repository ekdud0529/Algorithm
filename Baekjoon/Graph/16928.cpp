#include <bits/stdc++.h>
using namespace std;

int bridge[15][2];
int	snake[15][2];
int cnt_min = 100000;
bool check[101];

int check_snake(int m, int index)
{
	for(int i=0; i<m; i++)
	{
		if(snake[i][0] == index)
			return snake[i][1];
	}	
	return -1;
}

int check_bridge(int n, int index)
{
	for(int i=0; i<n; i++)
	{
		if(bridge[i][0] == index)
			return bridge[i][1];
	}
	return -1;
}

int get_min_dice(int n, int m)
{
	queue<pair<int, int> > q;
	q.push({1, 0});
	check[1] = 0;
	
	while(!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		
		if(pos == 100)
		{
			if(cnt < cnt_min)
				cnt_min = cnt;
			continue;
		}

		for(int i=1; i<=6; i++)
		{
			if((pos + i > 100) || check[pos+i])
				continue;;
				
			int move;
			if(((move = check_snake(m, pos+i)) >= 0))
			{
				q.push({move, cnt+1});
			}
			else if(((move = check_bridge(n, pos+i)) >= 0))
			{
				q.push({move, cnt+1});
			}
			else
			{
				q.push({pos+i, cnt+1});
			}
			check[pos+i] = true;
		}
	}
	return cnt_min;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		cin >> bridge[i][0] >> bridge[i][1];
	}
	for(int i=0; i<m; i++)
	{
		cin >> snake[i][0] >> snake[i][1];
	}
	
	cout << get_min_dice(n ,m);
	return 0;
}
