#include <bits/stdc++.h>
using namespace std;

int x[11], y[11];

int main(int argc, char** argv) {
	int i;
	for(i=0;i<10;i++){
		scanf("%d", &x[i]);
	}
	for(i=0;i<10;i++){
		scanf("%d", &y[i]);
	}
	sort(x, x+10);
	sort(y, y+10);
	printf("%d %d", x[9]+x[8]+x[7], y[9]+y[8]+y[7]);
	return 0;
}
