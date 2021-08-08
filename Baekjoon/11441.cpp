#include <bits/stdc++.h>
using namespace std;

int n[100001];
int main(int argc, char** argv) {
	int t, i, k, a, b, c;
	scanf("%d", &t);
	for(i=1;i<=t;i++){
		scanf("%d", &n[i]);
		n[i] += n[i-1];
	}
	scanf("%d", &c);
	for(i=0;i<c;i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", n[b]-n[a-1]);
	}
	return 0;
}
