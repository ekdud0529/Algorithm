#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100][100];

int main(int argc, char** argv) {
	int i, j, n, m, k, t, s;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for(i=0;i<m;i++){
		for(j=0;j<k;j++){
			scanf("%d", &b[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(s=0;s<k;s++){
			t=0;
			for(j=0;j<m;j++){
				t += a[i][j]*b[j][s];
			}
			printf("%d ", t);
		}	
		printf("\n");
	}
	return 0;
}
