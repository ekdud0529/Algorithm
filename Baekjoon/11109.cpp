#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, d, s, p, t;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d %d %d", &d, &n, &s, &p);
		if(d+n*p<n*s){
			printf("parallelize\n");
		}
		else if(d+n*p==n*s){
			printf("does not matter\n");
		}
		else{
			printf("do not parallelize\n");
		}
	}
	return 0;
}
