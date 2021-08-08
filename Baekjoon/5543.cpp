#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a=2000, b, c=2000, i;
	for(i=0;i<3;i++){
		scanf("%d", &b);
		if(b<a){
			a = b;
		}
	}
	for(i=0;i<2;i++){
		scanf("%d", &b);
		if(b<c){
			c = b;
		}
	}
	printf("%d", a+c-50);
	return 0;
}
