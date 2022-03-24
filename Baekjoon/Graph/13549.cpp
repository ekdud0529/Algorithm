#include <bits/stdc++.h>
using namespace std;

int min_sec = 1000000;
bool visited[1000000];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	queue<pair<int, int> > subin;
	subin.push({n, 0});
	
	while(!subin.empty())
	{
		int pos = subin.front().first;
		int sec = subin.front().second;
		visited[pos] = true;
		subin.pop();
		
		if(pos == k)
		{
			if(sec < min_sec) min_sec = sec;
			continue;
		}
		if((pos + 1 <= 100000) && !visited[pos+1]) subin.push({pos+1, sec+1});
		if((pos - 1 >= 0) && !visited[pos-1]) subin.push({pos-1, sec+1});
		if((pos * 2 <= 100000) && !visited[pos*2]) subin.push({pos*2, sec});
	}
	cout << min_sec;
	return 0;
}
