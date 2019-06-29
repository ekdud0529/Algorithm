#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main(int argc, char** argv) {
	int i, j, n, max=0;
	float p = 0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
		p += a[i];
	}
	for(i=0;i<n;i++){
		if(max<a[i]) max = a[i];
	}
	p = ((p*100)/max)/n;
	printf("%f", p);
	return 0;
}
