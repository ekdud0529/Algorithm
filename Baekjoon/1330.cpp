#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	scanf("%d %d", &a, &b);
	if(a>b) printf(">");
	else if(a==b) printf("==");
	else printf("<");
	return 0;
}
