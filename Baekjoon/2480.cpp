#include <bits/stdc++.h>
using namespace std;

int n[4];

int main(int argc, char** argv) {
	int i;
	for(i=0;i<3;i++){
		scanf("%d", &n[i]);
	}
	sort(n, n+3);
	if(n[0]==n[1]&&n[1]==n[2]){
		printf("%d", 10000+n[0]*1000);
	}
	else if(n[0]==n[1]||n[1]==n[2]){
		printf("%d", 1000+n[1]*100);
	}
	else{
		printf("%d", n[2]*100);
	}
	return 0;
}
