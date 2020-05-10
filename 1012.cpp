#include <bits/stdc++.h>
using namespace std;

int gd[50][50], m ,n;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool ch[50][50];

void dfs(int y, int x){
	ch[y][x] = true;
	for(int i=0; i<4; i++){
		int ny=y+dy[i], nx=x+dx[i];
		if(ny>=0 && ny<n && nx>=0 && nx<m && ch[ny][nx]==false && gd[ny][nx]==1){
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv) {
	int t, k, worm;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d %d", &m, &n, &k);
		for(int j=0; j<k; j++){
			int x, y;
			scanf("%d %d", &x, &y);
			gd[y][x] = 1;
		}
		worm=0;
		for(int a=0; a<n; a++){
			for(int b=0; b<m; b++){
				if(ch[a][b]==true || gd[a][b]==0) continue;
				dfs(a, b);
				worm++;
			}
		}
		printf("%d\n", worm);
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				gd[j][k]=0;
				ch[j][k]=false;
			}
		}
	}
	return 0;
}
