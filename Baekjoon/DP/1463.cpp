#include <bits/stdc++.h>
using namespace std;

int one[1000001];

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	one[1] = 0;
	one[2] = 1;
	one[3] = 1;
	for(int i=4; i<=n; i++){
		int res = i;
		if(i%3==0) res = min(res, one[i/3]+1);
		if(i%2==0) res = min(res, one[i/2]+1);
		res = min(res, one[i-1]+1);
		one[i] = res;
	}
	printf("%d", one[n]);
	return 0;
}
