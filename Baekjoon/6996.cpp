#include <bits/stdc++.h>
using namespace std;

char a[101], b[101], c[101], d[101];

int main(int argc, char** argv) {
	int i, n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s %s", a, b);
		strcpy(c, a);
		strcpy(d, b);
		sort(a, a+strlen(a));
		sort(b, b+strlen(b));
		if(!strcmp(a, b)){
			printf("%s & %s are anagrams.\n", c, d);
		}
		else{
			printf("%s & %s are NOT anagrams.\n", c, d);
		}
	}
	return 0;
}
