#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int m, n, i, k;
	scanf("%d %d", &m, &n);
	for(i=m;i<=n;i++){
		if(i==1) continue;
		else if(i==2) printf("2\n");
		else if(i%2==0) continue;
		else{
			for(k=3;k*k<i;k+=2){
				if(i%k==0) break;
			}
			if(k*k>i) printf("%d\n", i);
		}
	}
	return 0;
}
