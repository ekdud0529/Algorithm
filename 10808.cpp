#include <bits/stdc++.h>
using namespace std;

char s[101];
int a[27];

int main(int argc, char** argv) {
	int i, t;
	scanf("%s", &s);
	for(i=0;i<strlen(s);i++){
		t=0;
		t = s[i]-97;
		a[t] += 1;
	}
	for(i=0;i<26;i++){
		printf("%d ", a[i]);
	}
	return 0;
}
