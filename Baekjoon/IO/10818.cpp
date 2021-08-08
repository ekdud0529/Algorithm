#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, min=1000000, max=-1000000, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n<min) min = n;
		else if(n>max) max = n;
	}
	printf("%d %d", min, max);
	return 0;
}
