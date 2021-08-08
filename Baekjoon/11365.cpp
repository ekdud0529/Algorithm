#include <bits/stdc++.h>
using namespace std;

char s[501];

int main(int argc, char** argv) {
	int l, i;
	while(1){
		scanf("%[^\n]", s);
		getchar();
		if(strcmp(s, "END")==0) break;
		l = strlen(s);
		for(i=l-1;i>=0;i--) printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
