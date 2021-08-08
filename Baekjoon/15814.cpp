#include <bits/stdc++.h>
using namespace std;

char s[101];

int main() {
	int t, a, b;
	scanf("%s", s);
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d", &a, &b);
		char tmp;
		tmp = s[a];
		s[a] = s[b];
		s[b] = tmp;
	}
	cout << s;
	return 0;
}
