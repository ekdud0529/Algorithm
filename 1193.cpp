#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, cnt=1, c=1, m, s;
	scanf("%d", &n);
	while(n>cnt){
		c++;
		cnt+=c;
	}
	n = n-(cnt-c);
	if(c%2!=0){
		s = c; m = 1;
		for(int i=0; i<n-1; i++){
			s--; m++;
		}
	}
	else{
		s = 1; m = c;
		for(int i=0; i<n-1; i++){
			s++; m--;
		}
	}
	printf("%d/%d", s, m);
	return 0;
}
