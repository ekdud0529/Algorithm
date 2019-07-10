#include <bits/stdc++.h>
using namespace std;

int t[201][4];

int main(int argc, char** argv) {
	int i, n, k, j, a;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d %d", &t[i][0], &t[i][1], &t[i][2]);
	}
	for(i=0;i<3;i++){
		for(k=0;k<n;k++){
			if(t[k][i]==0) continue;
			a=0;
			for(j=k+1;j<n;j++){
				if(t[k][i]==t[j][i]){
					t[j][i] = 0;
					a++;
				}
			}
			if(a!=0) t[k][i] = 0;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n", t[i][0]+t[i][1]+t[i][2]);
	}
	return 0;
}
