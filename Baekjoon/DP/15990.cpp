#include <bits/stdc++.h>
using namespace std;

long long sum[1000001][4];

int main(int argc, char** argv) {
	int t, n;
	scanf("%d", &t);
	
	for(int i=1; i<=1000000; i++){
		for(int j=1; j<=3; j++){
			if(i>j){
				if(j==1) sum[i][j] = (sum[i-j][2]+sum[i-j][3])%1000000009;
				else if(j==2) sum[i][j] = (sum[i-j][1]+sum[i-j][3])%1000000009;
				else if(j==3) sum[i][j] = (sum[i-j][1]+sum[i-j][2])%1000000009;
			}
			else if(i==j) sum[i][j] = 1;
		}
	}
	
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("%d\n", (sum[n][1]+sum[n][2]+sum[n][3])%1000000009);
	}
	
	
	return 0;
}
