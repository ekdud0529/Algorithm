#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, i, v, e;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &v, &e);
		printf("%d\n", 2-v+e);
	}
	return 0;
}
