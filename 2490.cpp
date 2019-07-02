#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, i, k, a;
	for(i=0;i<3;i++){
		t=0;
		for(k=0;k<4;k++){
			scanf("%d", &a);
			t += a;
		}
		switch(t){
			case 0:
				printf("D");
				break;
			case 1:
				printf("C");
				break;
			case 2:
				printf("B");
				break;
			case 3:
				printf("A");
				break;
			default:
				printf("E");
		}
		printf("\n");
	}
	return 0;
} 
