#include <bits/stdc++.h>
using namespace std;

int n, m;
bool check[2000][2000];
vector<pair<int, int> > edge;
vector<int> f[2000];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int from, to;
		cin >> from >> to;
		edge.push_back({from, to});
		edge.push_back({to, from});
		check[from][to] = true;
		check[to][from] = true;
		f[from].push_back(to);
		f[to].push_back(from);
	}
	
	m *= 2;
	
	for(int i=0; i<m; i++)
	{
		for(int k=0; k<m; k++)
		{
			int A = edge[i].first;
			int B = edge[i].second;
			
			int C = edge[k].first;
			int D = edge[k].second;
			
			if(A == B || A == C || A == D || B == C || B == D || C == D) continue;
			
			if(!check[B][C]) continue;
			
			for(int j=0; j<f[D].size(); j++)
			{
				int E = f[D][j];
				if(E == A || E == B || E == C || E == D) continue;
				
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
