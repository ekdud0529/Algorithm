#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, h, w, n, i, x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &h, &w, &n);
		x = n/h;
		y = n%h;
		if(y==0){
			x--;
			y=h;
		}
		if(x+1<10) printf("%d0%d\n", y, 1+x);
		else printf("%d%d\n", y, 1+x);
	}
	return 0;
}
