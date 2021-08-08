#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, i, t;
	scanf("%d %d", &a, &b);
	t = a+b;
	for(i=3;;i++){
		if(t%i==0){
			if(a==2*(i+t/i-2)){
				break;
			}
		}
	}
	printf("%d %d", t/i, i);
	return 0;
}
