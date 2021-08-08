#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int m, n, k, cnt;
	scanf("%d %d %d", &m, &n, &k);
	if(k==m+n) cnt = 0;
	else if(n<=m/2){
		cnt = n;
		k -= m-n*2;
		if(k>0&&k%3!=0) cnt -= k/3+1;
		else if(k>0) cnt -= k/3;
	}
	else if(n>m/2){
		cnt = m/2;
		k -= n-m/2;
		k -= m%2;
		if(k>0&&k%3!=0) cnt -= k/3+1;
		else if(k>0) cnt -= k/3;
	}
	printf("%d", cnt);
	return 0;
}
