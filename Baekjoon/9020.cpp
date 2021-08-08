#include <bits/stdc++.h>
using namespace std;

int p[2];

int main(int argc, char** argv) {
	int t, n, i, j, k, a;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		if(n==4){
			printf("2 2\n");
			continue;
		}
		a=0; p[0]=0; p[1]=10000;
		for(k=3;k<=n/2;k+=2){
			for(j=3;j*j<=k;j+=2){
				if(k%j==0) break;
			}
			if(j*j>k){
				a = n-k;
				for(j=3;j*j<=a;j+=2){
					if(a%j==0)break;
				}
				if(j*j>a){
					if(p[1]-p[0]>a-k){
						p[0] = k;
						p[1] = a;
					}
				}
			}
			
		}
		printf("%d %d\n", p[0], p[1]);
	}
	return 0;
}
