#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int max=0, n=0;
	for(int i=0; i<4; i++){
		int r, t;
		scanf("%d %d", &r, &t);
		n -= r;
		n += t;
		if(n > max) max = n;
	}
	printf("%d", max);
	return 0;
}
