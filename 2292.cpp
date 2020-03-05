#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, cnt=1, l=0;
	scanf("%d", &n);
	while(n>cnt){
		l+=6;
		cnt+=l;
	}
	l/=6;
	printf("%d", l+1);
	return 0;
}
