#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, n, w, h, k, a;
	scanf("%d %d %d", &n, &w, &h);
	k = w*w+h*h;
	for(i=0;i<n;i++){
		scanf("%d", &a);
		if(a*a>k) printf("NE\n");
		else printf("DA\n");
	}
	return 0;
}
