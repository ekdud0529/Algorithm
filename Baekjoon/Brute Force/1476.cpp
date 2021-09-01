#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b, c, i, e=1, s=1, m=1, n=1;
	scanf("%d %d %d", &a, &b, &c);
	while(!(a==e&&b==s&&c==m)){
		e++;
		if(e>15){
			e=1;
		}
		s++;
		if(s>28){
			s=1;
		}
		m++;
		if(m>19){
			m=1;
		}
		n++;
	}
	printf("%d", n);
	return 0;
}
