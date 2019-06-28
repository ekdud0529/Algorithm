#include <bits/stdc++.h>
#include <string>
using namespace std;

char s[21];

int main(int argc, char** argv) {
	int n, i, k, t, j;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		scanf("%s", s);
		for(k=0;k<strlen(s);k++){
			for(j=0;j<n;j++){
				printf("%c", s[k]);				
			}
		}
		printf("\n");
	}
	return 0;
}
