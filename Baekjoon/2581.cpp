#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, m, cnt=0, min, k;
	scanf("%d %d", &n, &m);
	vector<int > dc;
	for(int i=n; i<=m; i++){
		if(i==1) continue;
		if(i==2){
			dc.push_back(i);
			cnt+=i;
		}
		if(i%2==0) continue;
		for(k=3; k*k<=i; k+=2){
			if(i%k==0) break;
		}
		if(k*k>i){
			cnt+=i;
			dc.push_back(i);
		}
	}
	if(dc.size()==0) printf("-1");
	else printf("%d\n%d", cnt, dc[0]);
	return 0;
}
