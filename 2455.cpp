#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d, m=0;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	if(b>b-c+d) m = b;
	else m = b-c+d;
	
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	if(m-a+b>m) m = m-a+b;
	
	printf("%d", m);
	return 0;
}
