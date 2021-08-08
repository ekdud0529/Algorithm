#include <bits/stdc++.h>
using namespace std;

int t[1000];

int main(int argc, char** argv) {
	int n, cnt=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &t[i]);
	}
	
	sort(t, t+n);
	
	for(int i=1; i<n; i++){
		t[i] += t[i-1];
	}
	
	for(int i=0; i<n; i++){
		cnt += t[i];
	}
	
	printf("%d", cnt);
	
	return 0;
}
