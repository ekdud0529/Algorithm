#include <bits/stdc++.h>
using namespace std;

char s[101];

int main(int argc, char** argv) {
	int l, i;
	scanf("%s", s);
	l = strlen(s);
	for(i=0;i<l;i++){
		if(s[i]>='A'&&s[i]<='Z') printf("%c", s[i]);
	}
	return 0;
}
