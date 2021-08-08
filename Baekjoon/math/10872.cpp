#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, a=1;
	scanf("%d", &n);
	for(i=2;i<=n;i++) a*=i;
	printf("%d", a); 
	return 0;
}
