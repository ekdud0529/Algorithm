#include <bits/stdc++.h>
using namespace std;

int n, cnt, dcnt=0, apart[26][26];
bool ch[26][26];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x){
	cnt++;
	ch[y][x] = true;
	for(int i=0; i<4; i++){
		int ny=y+dy[i], nx=x+dx[i];
		if(ny<n && ny>=0 && nx<n && nx>=0 && ch[ny][nx]==false && apart[ny][nx]==1){
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv) {
	scanf("%d", &n);
	vector<int> s;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %1d", &apart[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(apart[i][j]==0 || ch[i][j]==true) continue;
			cnt=0;
			dcnt++;
			dfs(i, j);
			s.push_back(cnt);
		}
	}
	printf("%d\n", dcnt);
	sort(s.begin(), s.end());
	int sz=s.size();
	for(int i=0; i<sz; i++) printf("%d\n", s[i]);
	return 0;
}
