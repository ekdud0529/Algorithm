#include <bits/stdc++.h>
#include <string>
using namespace std;

int n[10];
char s[100];

int main(int argc, char** argv) {
	int a, b, c, t, i;
	scanf("%d %d %d", &a, &b, &c);
	t = a*b*c;
	sprintf(s, "%d", t);
	for(i=0;i<strlen(s);i++){
		n[s[i]-'0']++;
	}
	for(i=0;i<10;i++){
		printf("%d\n", n[i]);
	}
	return 0;
}
