#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a*(b%10));
	printf("%d\n", a*((b%100)/10));
	printf("%d\n", a*(b/100));
	printf("%d", a*b);
	return 0;
}
