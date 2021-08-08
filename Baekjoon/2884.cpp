#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	scanf("%d %d", &a, &b);
	if(a>0){
		if(b<45) printf("%d %d", a-1, 60-(45-b));
		else printf("%d %d", a, b-45);
	}
	else if(a==0){
		if(b<45) printf("%d %d", 23, 60-(45-b));
		else printf("%d %d", a, b-45);
	}
	return 0;
}
