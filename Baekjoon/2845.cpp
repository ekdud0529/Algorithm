#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d, i, j, k, p;
	scanf("%d %d", &a, &b);
	p=a*b;
	scanf("%d %d %d %d %d", &c, &d, &i, &j, &k);
	printf("%d %d %d %d %d", c-p, d-p, i-p, j-p, k-p);
	return 0;
}
