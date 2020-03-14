#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	char a[4], b[4];
	scanf("%s %s", a, b);
	int c=100, n=0, m=0;
	for(int i=2; i>-1; i--){
		n += (a[i]-'0')*c;
		c/=10;
	}
	c=100;
	for(int i=2; i>-1; i--){
		m += (b[i]-'0')*c;
		c/=10;
	}
	printf("%d", (n<m)? m:n);
	return 0;
}
