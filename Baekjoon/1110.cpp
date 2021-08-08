#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i=0, a, t=0, m=0;
	scanf("%d", &n);
    a=n;
	while(1){
		t = a/10 + a%10;
		m = (a%10)*10 + t%10;
		a = m;
		i++;
        if(n==0||n==m)break;
	}
	printf("%d", i);
	return 0;
}
