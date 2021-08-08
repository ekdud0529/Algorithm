#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, n, a, b=0, c=0, t, k, s=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		t=1;
		scanf("%d", &a);
		b = a%10;
		c = a/10;
		for(k=0;k<b;k++){
			t *= c;
		}
		s += t;
	}
	printf("%d", s);
	return 0;
}
