#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, b, d, i, j, k, p;
	scanf("%d", &a);
	d = 1;
	for(i=1;i<2*a;i++){
		if(i<a+1){
			for(j=0;j<i;j++){
				printf("*");
			}
			for(k=0;k<2*a-2*i;k++){
				printf(" ");
			}
			for(p=0;p<i;p++){
				printf("*");
			}
			printf("\n");
		}
		else{
			for(j=0;j<a-d;j++){
				printf("*");
			}
			for(k=0;k<2*a-2*(a-d);k++){
				printf(" ");
			}
			for(p=0;p<a-d;p++){
				printf("*");
			}
			d+=1;
			printf("\n");
		}
	}
	return 0;
}
