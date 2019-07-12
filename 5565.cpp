#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, i, v;
	scanf("%d", &t);
	for(i=0;i<9;i++){
		scanf("%d", &v);
		t -= v;
	}
	printf("%d", t);
	return 0;
}
