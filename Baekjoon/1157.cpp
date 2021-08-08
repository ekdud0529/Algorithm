#include <bits/stdc++.h>
#include <string>
using namespace std;

int a[27];
char s[1000000];

int main(int argc, char** argv) {
	int i, max=0, c;
	char d;
	scanf("%s", s);
	c = strlen(s);
	for(i=0;i<c;i++){
		if(s[i]>='a') a[s[i]-'a']++;
		else a[s[i]-'A']++;
	}
	for(i=0;i<26;i++){
		if(max<a[i]){
			max = a[i];
			c = i;
			d = 'A'+i;
		}
		else if(max==a[i]){
			d = '?';
		}
	}
	printf("%c", d);
	return 0;
}
