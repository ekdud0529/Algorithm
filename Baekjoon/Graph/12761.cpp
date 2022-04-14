#include <bits/stdc++.h>
using namespace std;

bool visited[100001];

int main(int argc, char** argv) {
	int a, b, n, m;
	int min_move = 1000000;
	cin >> a >> b >> n >> m;
	
	int move[3] = {1, a, b};
	
	queue<pair<int, int> > pos;
	pos.push({n, 0});
	
	while(!pos.empty())
	{
		int dong = pos.front().first;
		int	cnt = pos.front().second;
		visited[dong] = true;
		pos.pop();
		
		cout << dong << " " << cnt << "\n";
		if(dong == m)
		{
			cout << cnt;
			break; 
		}
		for(int i=0; i<3; i++)
		{
			if(!visited[dong+move[i]] && (dong + move[i] <= 100000))
			{
				visited[dong+move[i]] = true;
				pos.push({dong+move[i], cnt+1});
			}
			if(!visited[dong-move[i]] && (0 <= dong - move[i]))
			{
				visited[dong-move[i]] = true;
				pos.push({dong-move[i], cnt+1});
			}
			if(move[i] == 1) continue;
			if(!visited[dong*move[i]] && (dong * move[i] <= 100000))
			{
				visited[dong*move[i]] = true;
				pos.push({dong*move[i], cnt+1});	
			}
		}
	}
	return 0;
}
