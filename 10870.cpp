#include <bits/stdc++.h>
using namespace std;

int fb(int a){
	if(a==0) return 0;
	else if(a==1) return 1;
	return fb(a-1) + fb(a-2);
}

int main(int argc, char** argv) {
	int n, f;
	scanf("%d", &n);
	f = fb(n);
	printf("%d", f);
	return 0;
}
