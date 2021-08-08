#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, k, c, cnt=0, size;
	scanf("%d %d", &n, &k);
	vector<int > coin(n);
	for(int i=0; i<n; i++){
		scanf("%d", &c);
		coin.push_back(c);
	}
	size = coin.size();
	for(int i=size-1; i>=0; i--){
		cnt += k/coin[i];
		k %= coin[i];
		if(k==0) break;
	}
	printf("%d", cnt);
	return 0;
}
