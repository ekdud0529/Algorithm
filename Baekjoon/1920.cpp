#include <bits/stdc++.h>

using namespace std;

int a[100001];

int search(int left, int right, int m){
	while(left<=right){
		int mid = (left+right)/2;
		if(a[mid]<m){
			left = mid + 1;
		}
		else if(a[mid]>m){
			right = mid - 1;
		}
		else{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char** argv) {
	int i, k, n, m, M, j;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n);
	scanf("%d", &M);
	for(k=0;k<M;k++){
		scanf("%d", &m);
		printf("%d\n", search(0, n, m));
		}
	return 0;
}
