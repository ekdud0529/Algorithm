#include <bits/stdc++.h>
using namespace std;

int n, k, l;
queue<pair<int, char> > direc;
vector<pair<int, int> > apple;
pair<int, int> turn[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int> > body;

bool ch_apple(int x, int y)
{
	for(int i=0; i<apple.size(); i++)
	{
		int nx = apple[i].first;
		int ny = apple[i].second;
		
		if((nx == x) && (ny == y))
		{
			apple.erase(apple.begin() + i);
			return true;
		}
	}
	return false;
}

bool ch_body(int x, int y)
{
	for(int i=0; i<body.size(); i++)
	{
		if((body[i].first == x) && (body[i].second == y))
			return true;
	}
	return false;
}

int s_move(int sec)
{
	int dir = 0;
	int x = 1;
	int y = 1;
	body.push_back({x, y});
	
	while((x <= n) && (y <= n) && (1 <= x) && (1 <= y))
	{
		x += turn[dir].first;
		y += turn[dir].second;
		sec++;
		
		if(ch_body(x, y)) return sec;
		if(!ch_apple(x, y)) body.erase(body.begin());
		if(direc.front().first == sec)
		{
			if(direc.front().second == 'D')
			{
				dir = (dir + 1) % 4;
			}
			else
			{
				if(dir == 0) dir = 3;
				else dir--;
			}
			direc.pop();
		}
		body.push_back({x, y});
	}
	return (sec);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> k;
	for(int i=0; i<k; i++)
	{
		int x, y;
		cin >> x >> y;
		apple.push_back({x, y});
	}
	cin >> l;
	int x;
	char c;
	for(int i=0; i<l; i++)
	{
		cin >> x >> c;
		direc.push({x, c});
	}
	
	cout << s_move(0);
	return 0;
}
