#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, i, c=0;
	scanf("%d %d", &a, &b);
	if(a>b) a -= b;
	for(i=0;i<=b;i++){
		if((i*a)%b!=0){
			c++;
		}
	}
	printf("%d", c);
	return 0;
}
