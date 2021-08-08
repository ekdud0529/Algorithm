#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, cnt, i, k;
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		cnt=0;
		for(i=n+1;i<=n*2;i++){
			if(i==1) continue;
			else if(i==2) cnt++;
			else if(i%2==0) continue;
			else{
				for(k=3;k*k<i;k+=2){
					if(i%k==0) break;
				}
				if(k*k>i) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
