#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, n, r, e, c;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d %d", &r, &e, &c);
		if(r>e-c) printf("do not advertise\n");
		else if(r==e-c) printf("does not matter\n");
		else printf("advertise\n");
	}
	return 0;
}
