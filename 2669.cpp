#include <bits/stdc++.h>
using namespace std;

int p[100][100];

int main(int argc, char** argv) {
	int t, i, k, a, b, x, y, cnt=0;
	t=4;
	while(t--){
		scanf("%d %d %d %d", &a, &b, &x, &y);
		for(i=a;i<x;i++){
			for(k=b;k<y;k++){
				if(p[i][k]==0){
					p[i][k]++;
					cnt++;
				}
				
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
