#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	long long a, b, i;
	scanf("%lld %lld", &a, &b);
	if(a==b){
		printf("0");
	}
	else if(a>b){
		printf("%lld\n", a-b-1);
		for(i=b+1;i<a;i++){
			printf("%lld ", i);
		}
	}
	else{
		printf("%lld\n", b-a-1);
		for(i=a+1;i<b;i++){
		printf("%lld ", i);
		}
	}
	return 0;
}
