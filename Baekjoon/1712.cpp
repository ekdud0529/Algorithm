#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	long long a, b, c, g;
	scanf("%lld %lld %lld", &a, &b, &c);
	if(b>=c) printf("-1");
	else{
		g = a/(c-b);
		printf("%lld", g+1);
	}
	return 0;
}
