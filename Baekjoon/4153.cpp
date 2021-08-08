#include <bits/stdc++.h>
using namespace std;

int n[4];

int main(int argc, char** argv) {
	while(1){
		for(int i=0;i<3;i++){
			scanf("%d", &n[i]);
		}
		if(n[0]==0){
			break;
		}
		else{
			sort(n, n+3);
			if(n[0]*n[0]+n[1]*n[1]==n[2]*n[2]){
				printf("right\n");
			}
			else{
				printf("wrong\n");
			}	
		}
		
	}
	return 0;
}
