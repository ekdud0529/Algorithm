#include <bits/stdc++.h>
using namespace std;

char s[10], t[1001][10], cnt[1001];

int main(int argc, char** argv) {
	int i, n, k, c=0;
	scanf("%s", s);
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", t[i]);
	}
	for(i=0;i<n;i++){
		for(k=0;k<10;k++){
			if(s[k]=='*') continue;
			else if(s[k]!=t[i][k]){
				t[i][0] = '.';
				break;
			}
		}
		if(t[i][0]!='.') c++;
	}
	printf("%d\n", c);
	for(i=0;i<n;i++){
		if(t[i][0]!='.') printf("%s\n", t[i]);
	}
	return 0;
}
