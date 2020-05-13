#include <bits/stdc++.h>
using namespace std;

string md[251];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool ch[251][251];
int w=0, sh=0, r, c;

void bfs(int y, int x){
	int o=0, v=0;
	ch[y][x] = true;
	queue<pair<int, int> > q;
	q.push({y, x});
	if(md[y][x]=='v') v++;
	else if(md[y][x]=='o') o++;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny=y+dy[i], nx=x+dx[i];
			if(ny>=r || nx>=c || ny<0 || nx<0) continue;
			if(ch[ny][nx]==true || md[ny][nx]=='#') continue;
			if(md[ny][nx]=='o') o++;
			else if(md[ny][nx]=='v') v++;
			ch[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	if(o>v) sh+=o;
	else w+=v;
}

int main(int argc, char** argv) {
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		cin >> md[i];
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ch[i][j] || md[i][j]=='#') continue;
			bfs(i, j);
		}
	}
	printf("%d %d", sh, w);
	return 0;
}
