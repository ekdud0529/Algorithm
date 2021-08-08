#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	int a, i, n, cnt = 0, k;
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%d", &n);
		if(n==1) continue;
		else if (n==2) cnt++;
		else
		{
			if(n%2==0) continue;
			for(k=3;k*k<=n;k+=2){
				if (n%k==0) break;
			}
			if(k*k>n) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
