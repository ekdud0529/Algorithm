#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, a, b, c;
	scanf("%d", &n);
	a = n/5;
	for(i=a;i>=0;i--){
		b = 5*i;
		c = (n-b)/3;
		if(n==b+3*c){
			printf("%d", i+c);
			break;
		}
	}
	if(i<0){
		printf("-1");
	}
	return 0;
}
