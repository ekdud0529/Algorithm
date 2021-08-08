#include <bits/stdc++.h>
using namespace std;

int num[30];

int main(int argc, char *argv[]) {
	int i, a, k;
	for(i=1;i<29;i++){
	scanf("%d", &a);
	num[a-1]=1;
	}
	for(k=0;k<30;k++){
		if(num[k]==0){
		printf("%d\n", k+1);
		}
	}
	return 0;
}
