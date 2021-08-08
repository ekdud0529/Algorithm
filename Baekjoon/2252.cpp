#include <bits/stdc++.h>
using namespace std;
 
 int cnt[32001];
 
int main(int argc, char** argv) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > adj(n+1);
	queue<int> q;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		cnt[b]++;
		adj[a].push_back(b);
	}
	for(int i=1; i<=n; i++){
		if(cnt[i]==0) q.push(i);
	}
	int qsize = q.size();
	for(int i=0; i<qsize; i++){
		int ch = q.front();
		q.pop();
		printf("%d ", ch);
		int s = adj[ch].size();
		for(int j=0; j<s; j++){
			cnt[adj[ch][j]]--;
			if(cnt[adj[ch][j]]==0){
				q.push(adj[ch][j]);
				qsize++;
			}
		}
	}
	return 0;
}
