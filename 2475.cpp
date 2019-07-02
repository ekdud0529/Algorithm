#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, a, t=0;
	for(i=0;i<5;i++){
		scanf("%d", &a);
		t += a*a;
	}
	printf("%d", t%10);
	return 0;
}
