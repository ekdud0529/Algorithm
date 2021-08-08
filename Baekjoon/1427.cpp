#include <bits/stdc++.h>
using namespace std;

char n[11];
int main(int argc, char** argv) {
	int i;
	scanf("%s", &n);
	sort(n, n+strlen(n));
	for(i=strlen(n)-1;i>=0;i--){
		printf("%c", n[i]);
	}
	return 0;
}
