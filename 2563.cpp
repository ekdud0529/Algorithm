#include <bits/stdc++.h>
using namespace std;

int t[101][101], s[101][3];

int main(int argc, char** argv) {
	int i, k, j, n, c=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &s[i][0], &s[i][1]);
	}
	for(k=0;k<n;k++){
		for(j=s[k][1];j<s[k][1]+10;j++){
			for(i=s[k][0];i<s[k][0]+10;i++){
				t[i][j] = 1;
			}
		}
	}
	for(i=0;i<100;i++){
		for(k=0;k<100;k++){
			if(t[i][k]==1) c++;
		}
	}
	printf("%d", c);
	return 0;
}
