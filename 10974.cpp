#include <bits/stdc++.h>
using namespace std;

int num[8], ch[9];
int n;

void f(int pos){
	if(pos==n){
		for(int i=0; i<pos; i++){
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1; i<=n; i++){
		if(ch[i]!=1){
			num[pos] = i;
			ch[i] = 1;
			f(pos+1);
			ch[i] = 0;
		}
	}
}

int main(int argc, char** argv) {
	scanf("%d", &n);
	f(0);
	return 0;
}
