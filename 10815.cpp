#include <bits/stdc++.h>
using namespace std;

int N[500001];

int search(int l, int r, int m){
	while(l<=r){
		int mid = (l+r)/2;
		if(N[mid]<m){
			l = mid + 1;
		}
		else if(N[mid]>m){
			r = mid - 1;
		}
		else{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char** argv) {
	int i, k, m, a, n;
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%d", &N[i]);
	}
	sort(N,N+a);
	scanf("%d", &n);
	for(k=0;k<n;k++){
		scanf("%d", &m);
		printf("%d\n", search(0, a, m));
	}
	return 0;
}
