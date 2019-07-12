#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, n, k=0;
	for(i=0;i<4;i++){
		scanf("%d", &n);
		k += n;
	}
	printf("%d\n%d", k/60, k%60);
	return 0;
}
