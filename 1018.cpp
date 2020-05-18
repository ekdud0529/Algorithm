#include <bits/stdc++.h>
using namespace std;

char ch[51][51];
bool wcheck[51][51], bcheck[51][51];

int main(int argc, char** argv) {
	int n, m, min=32;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", ch[i]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j+=2){
			if(i%2==0){
				if(ch[i][j] != 'W') wcheck[i][j] = true;
				if(j+1<m && ch[i][j+1] != 'B') wcheck[i][j+1] = true;
				if(ch[i][j] != 'B') bcheck[i][j] = true;
				if(j+1<m && ch[i][j+1] != 'W') bcheck[i][j+1] = true;
			}
			else{
				if(ch[i][j] != 'B') wcheck[i][j] = true;
				if(j+1<m && ch[i][j+1] != 'W') wcheck[i][j+1] = true;
				if(ch[i][j] != 'W') bcheck[i][j] = true;
				if(j+1<m && j+1<m && ch[i][j+1] != 'B') bcheck[i][j+1] = true;
			}
		}
	}
	
	for(int i=0; i<n-7; i++){
		for(int j=0; j<m-7; j++){
			int cntw=0, cntb=0;
			for(int y=i; y<i+8; y++){
				for(int x=j; x<j+8; x++){
					if(wcheck[y][x] == true) cntw++;
					if(bcheck[y][x] == true) cntb++;
				}
			}
			if(cntb<cntw && min>cntb) min = cntb;
			else if(cntw<cntb && min>cntw) min = cntw;
		}
	}
	
	printf("%d", min);
	return 0;
}
