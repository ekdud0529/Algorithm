#include <bits/stdc++.h>

using namespace std;

int a[1000001];

int search(int l, int r, int d){
	while(l<=r){
		int mid = (l+r)/2;
			if(a[mid]>d){
				r = mid - 1;
			}
			else if(a[mid]<d){
				l = mid + 1;
			}
			else{
				return 1;
			}	
	}
	return 0;
}

int main(int argc, char** argv) {
	int t, n, i, j, k, m, d;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		for(j=0;j<n;j++){
			scanf("%d", &a[j]);
		}
		sort(a, a+n);
		scanf("%d", &m);
		for(k=0;k<m;k++){
			scanf("%d", &d);
			printf("%d\n", search(0, n-1, d));
		}

	}
	return 0;
}
