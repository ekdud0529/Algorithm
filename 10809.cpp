#include <bits/stdc++.h>
using namespace std;

char s[101];
int a[27];
int main(int argc, char** argv) {
	int i, t;
	scanf("%s", &s);
	for(i=0;i<strlen(s);i++){
		t = s[i]-97;
		if(a[t]==0){
			a[t] += i+1;	
		}
	}
	for(i=0;i<26;i++){
		if(a[i]>0){
			printf("%d ", a[i]-1);
		}
		else{
			printf("-1 ");
		}
	}
	return 0;
}
