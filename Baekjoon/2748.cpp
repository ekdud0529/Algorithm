#include <bits/stdc++.h>
using namespace std;

long long n[91];

int main(int argc, char** argv) {
	n[0]=0;
	n[1]=1;
	int t, i;
	scanf("%d", &t);
	for(i=0;i<t-1;i++){
		n[i+2]=n[i]+n[i+1];
	}
	printf("%lld", n[t]);
	return 0;
}
