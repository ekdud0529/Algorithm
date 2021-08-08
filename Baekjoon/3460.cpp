#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, n, i, cnt;
	scanf("%d", &a);
	for(i=0;i<a;i++){
	scanf("%d", &n);
	cnt = 0;
	while (n>0){
		if(n%2==1){
			printf("%d ", cnt);
			cnt++;
		}
		else if(n/2==0&&n%2==1){
			printf("%d\n", cnt);
		}
		else {
			cnt++;
		}
		n /= 2;
	}
	}
	return 0;
}
