#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a>=b&&a>=c){
		if(b>=c) printf("%d", b);
		else printf("%d", c);
	}
	else if(b>=a&&b>=c){
		if(a>=c) printf("%d", a);
		else printf("%d", c);
	}
	else{
		if(a>=b) printf("%d", a);
		else printf("%d", b);
	}
	return 0;
}
