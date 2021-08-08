#include <bits/stdc++.h>
using namespace std;

int gd[100][100], n, ht = 1;
bool ch[100][100];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x){
	ch[y][x] = true;
	for(int i=0; i<4; i++){
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<n && ny>=0 && nx>=0 && nx<n && ch[ny][nx]==false && gd[ny][nx]>=ht){
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv) {
	int max=0, maxgd=1, cntgd, low=100;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &gd[i][j]);
			if(gd[i][j] > max) max = gd[i][j];
			if(gd[i][j] < low) low = gd[i][j];
		}
	}
	do{
		if(max == low) break;
		cntgd=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(gd[i][j] < ht || ch[i][j] == true) continue;
				cntgd++;
				dfs(i, j);
			}
		}
		if(maxgd < cntgd) maxgd = cntgd;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ch[i][j] = 0;
			}
		}
	}while(++ht <= max);
	printf("%d", maxgd);
	return 0;
}
