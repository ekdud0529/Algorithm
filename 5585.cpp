#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, cnt=0;
	scanf("%d", &n);
	n = 1000-n;
	cnt += n/500;
	n %= 500;
	cnt += n/100;
	n %= 100;
	cnt += n/50;
	n %= 50;
	cnt += n/10;
	n %= 10;
	cnt += n/5;
	n %= 5;
	cnt += n;
	printf("%d", cnt);
	return 0;
}
