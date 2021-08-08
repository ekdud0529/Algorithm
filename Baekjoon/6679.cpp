#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, t, p, h, i;
	for(i=1000;i<10000;i++){
		a = 0;
		b = 0;
		c = 0;
		t = i;
		p = i;
		h = i;
		while(t>0){
			a += t%12;
			t /= 12;
		}
		while(p>0){
			b += p%16;
			p /= 16;
		}
		while(h>0){
			c += h%10;
			h /= 10;
		}
		if(a==b&&b==c){
			printf("%d\n", i);
		}
	}
	return 0;
}
