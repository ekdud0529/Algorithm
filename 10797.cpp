#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, a, b, k=0;
	scanf("%d", &n);
	b = n%10;
	for(i=0;i<5;i++){
		scanf("%d", &a);
		if(a==b) k++;
	}
	printf("%d", k);
	return 0;
}
