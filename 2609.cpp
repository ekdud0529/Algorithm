#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	int min;
	if(a>b) min=b;
	else min=a;
	while(min>0){
		if(a%min==0&&b%min==0) break;
		min--;
	}
	return min;
}

int main(int argc, char** argv) {
	int i, a, b, g;
	scanf("%d %d", &a, &b);
	g = gcd(a, b);
	i = a*b/g;
	printf("%d\n%d", g, i);
	return 0;
}
