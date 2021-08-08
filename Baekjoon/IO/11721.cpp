#include <bits/stdc++.h>
using namespace std;

char n[101];
int main(int argc, char** argv) {
	scanf("%s", n);
	int i, b = strlen(n);
	for(i=0;i<b;i++){
		printf("%c", n[i]);
		if((i+1)%10==0){
			printf("\n");
		}
	}
	return 0;
}
