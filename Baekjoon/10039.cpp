#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int s, i, a=0;
	for(i=0;i<5;i++){
		scanf("%d", &s);
		if(s<40){
			s = 40;
		}
		a += s;
	}
	printf("%d", a/5);
	return 0;
}
