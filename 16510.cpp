#include <bits/stdc++.h>
using namespace std;

int t[200001];
long long c[200001];

int search(long w, int n){
	int l=0, r=n-1, mid;
	while(l<=r){
		mid = (r+l)/2;
		if(w==c[mid]) return mid+1;
		else if(c[mid]<w) l = mid+1;
		else r = mid-1;
	}
	return l;
}

int main(int argc, char** argv) {
	int i, n, m;
	long w;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++){
		scanf("%d", &t[i]);
		c[i] = c[i-1]+t[i];
	}
	for(i=0;i<m;i++){
		scanf("%ld", &w);
		if(w>c[n-1]) printf("%d\n", n);
		else if(w<c[0]) printf("0\n");
		else{
			printf("%d\n", search(w, n));
		}
	}
	return 0;
}
