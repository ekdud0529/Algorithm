#include <bits/stdc++.h>
#include <string>
using namespace std;

char s[81];

int main(int argc, char** argv) {
	int i, n, k, cnt, scr;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", s);
		cnt = 0;
		scr = 0;
		for(k=0;k<strlen(s);k++){
			if(s[k] == 'O'){
				cnt++;
				scr += cnt;
			}
			else cnt = 0;
		}
		printf("%d\n", scr);
	}
	return 0;
}
