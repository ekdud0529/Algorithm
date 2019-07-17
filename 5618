#include <bits/stdc++.h>
using namespace std;

int num[4];

int main(int argc, char** argv) {
	int n, i, j, k, a;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	printf("1\n");
	for(k=2;k<=num[0];k++){
		a=0;
		for(j=0;j<n;j++){
			if(num[j]%k!=0){
				break;
			}
			else{
				a++;
			}
		}
		if(a==n){
			printf("%d\n", k);
		}
	}
	return 0;
}
