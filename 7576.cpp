#include <bits/stdc++.h>
using namespace std;

int box[1001][1001];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int main(int argc, char** argv) {
	int m, n, cnt=0, kcnt=0;
	scanf("%d %d", &m, &n);
	queue<pair<int, int> > q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &box[i][j]);
			if(box[i][j]==1) q.push(make_pair(i, j));
			else if(box[i][j]==0) kcnt++;
		}
	}
	if(kcnt == 0){
		cout << 0;
		return 0;
	}
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=n || nx>=m || ny<0 || nx<0) continue;
				if(box[ny][nx] == 0){
					kcnt--;
					if(kcnt==0){
						cout << cnt;
						return 0;
					}
					box[ny][nx] = 1;
					q.push({ny, nx});
				}
			}
		}
	}
	if(kcnt > 0) cout << -1;
	else cout << cnt;
	return 0;
}
