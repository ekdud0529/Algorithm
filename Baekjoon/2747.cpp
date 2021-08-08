#include <bits/stdc++.h>
using namespace std;

int fb[100];

int dp(int a){
	fb[0] = 0;
	fb[1] = 1;
	
	if(fb[a]>0) return fb[a];
	if(a==0 || a==1) return fb[a];
	return fb[a] = dp(a-1) + dp(a-2);
}

int main(int argc, char** argv) {
	int n, d;
	scanf("%d", &n);
	printf("%d", dp(n));
	return 0;
}
