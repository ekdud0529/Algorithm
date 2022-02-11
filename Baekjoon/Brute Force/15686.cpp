#include <bits/stdc++.h>
using namespace std;

int n, m, min_dist = 30000;
int chosen[13];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

void get_chicken_road()
{
	int hsize = house.size();
	int csize = chicken.size();
	int sum_dist = 0;
	
	for(int i=0; i<hsize; i++)
	{
		int dist = 30000;
		
		for(int j=0; j<csize; j++)
		{
			if(chosen[j] == false) continue;
			int d = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
			if(dist > d)
				dist = d;
		}
		sum_dist += dist;
	}
	if(min_dist > sum_dist) min_dist = sum_dist;
}

void remain_chicken(int cnt, int start)
{
	if(cnt == m)
	{
		get_chicken_road();
		return ;
	}
	
	int c_size = chicken.size();
	for(int i=start; i<c_size; i++)
	{
		if(chosen[i]) continue;
		chosen[i] = true;
		remain_chicken(cnt + 1, i + 1);
		chosen[i] = false;
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int x;
			cin >> x;
			if(x == 2)
				chicken.push_back({i, j});
			else if(x == 1)
				house.push_back({i, j});
		}
	}
			
	remain_chicken(0, 0);
	cout << min_dist;
	return 0;
}
