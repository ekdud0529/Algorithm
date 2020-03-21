#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, k;
	vector<int> yo;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) yo.push_back(i);
	printf("<");
	vector<int>::iterator it=yo.begin();
	while(yo.size()!=1){
		int cnt=1;
		if(it==yo.end()) it = yo.begin();
		for(; cnt!=k; it++){
			if(it==yo.end()) it = yo.begin();
			cnt++;
		}
		if(it==yo.end()) it = yo.begin();
		printf("%d, ", *it);
		it = yo.erase(it);
	}
	printf("%d", yo.front());
	printf(">");
	return 0;
}
