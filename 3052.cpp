#include <bits/stdc++.h>
using namespace std;

int p[41];

int main(int argc, char** argv) {
	int n, cnt=0, i;
	for(i=0;i<10;i++){
		scanf("%d", &n);
		p[n%42]++;
	}
	for(i=0;i<42;i++){
		if(p[i]!=0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
