#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, a, b;
	char s;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin >> a >> s >> b;
		printf("%d\n", a+b);
	}
	return 0;
}
