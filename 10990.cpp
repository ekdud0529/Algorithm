#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	int n, k;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=0; j<n-i; j++) printf(" ");
		printf("*");
		for(k=1; k<i; k++) printf(" *");
		printf("\n");
	}
	return 0;
}
