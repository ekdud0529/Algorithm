#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, k, j, cnt=0, a, b, c;
	scanf("%d", &n);
	if(n<100) printf("%d", n);
	else if(n==1000) printf("144");
	else{
		for(i=n;i>=100;i--){
			a=i/100;
			b=(i%100)/10;
			c=i%10;
			if(b-c==a-b) cnt++;
		}
		printf("%d", cnt+99);
	}
	return 0;
}
