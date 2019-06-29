#include <bits/stdc++.h>
using namespace std;

int num[102];

int main(int argc, char** argv) {
	int n, i, t, cnt=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t);
		if(num[t]!=0) cnt++;
		else num[t] = 5;
	}
	printf("%d", cnt);
	return 0;
}
