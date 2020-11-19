#include <bits/stdc++.h>
using namespace std;

int a[1001], len[1001], v[1001];

void s(int i){
	if(i<0) return;
	s(v[i]);
	printf("%d ", a[i]);
}

int main(int argc, char** argv) {
	int n, max=0, p;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		len[i] = 1;
		v[i] = -1;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i]>a[j] && len[i]<=len[j]){
				len[i]++;
				v[i] = j;
			}
		}
		if(len[i] > max){
			max = len[i];
			p = i;
		}
	}
	
	printf("%d\n", max);
	s(p);
	
	return 0;
}
