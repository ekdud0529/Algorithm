#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, c, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		int c=i, cnt=i, t;
		while(c!=0){
			t = c%10;
			cnt += t;
			c/=10;
		}
		if(cnt==n) break;
	}
	if(i>n) printf("0");
	else printf("%d", i);
	return 0;
}
