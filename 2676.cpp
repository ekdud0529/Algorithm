#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, n, m, i, k, a;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &n, &m);
		if(n==m||m==0){
			printf("1\n");
		}
		else{
			a=1;
			for(k=n;k>m;k--){
				a += m;
			}
			printf("%d\n", a);
		}
	}
	return 0;
}
