#include <bits/stdc++.h>
using namespace std;

long long s[101][10];

int main(int argc, char** argv) {
	int n;
	
	for(int i=1; i<10; i++) s[1][i] = 1;  
	for(int i=2; i<=100; i++){
		for(int j=0; j<=9; j++){
			if(j-1>=0) s[i][j] += s[i-1][j-1];
			if(j+1<10) s[i][j] += s[i-1][j+1];
			s[i][j] %= 1000000000;
		}
	}
	
	long long sum=0;
	scanf("%d", &n);
	for(int j=0; j<=9; j++) sum += s[n][j];
	printf("%d\n", sum%1000000000);
	return 0;
}
