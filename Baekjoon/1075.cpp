#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, n, i;
	scanf("%d %d", &a, &b);
	n = a/100*100;
	for(i=0;i<100;i++){
		if(n%b==0){
			break;
		}
		else{
			n++;
		}
	}
	if(i<10){
		printf("0%d", i);
	}
	else{
		printf("%d", i);
	}
	return 0;
}
