#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, n, i, k, w, a;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		a=0;
		for(k=0;k<n;k++){
			scanf("%d", &w);
			a += w;
		}
		if(a<0){
			printf("Left\n");
		}
		else if(a>0){
			printf("Right\n");
		}
		else{
			printf("Equilibrium\n");
		}
	}
	return 0;
}
