#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, c, d, p, n, t;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
	n = a*p;
	if(p<=c) t = b;
	else t = b+d*(p-c);
	if(n>t) printf("%d", t);
	else printf("%d", n);
	return 0;
}
