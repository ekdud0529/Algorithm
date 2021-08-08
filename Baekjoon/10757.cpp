#include <bits/stdc++.h>
using namespace std;

char a[10002], b[10002];
int c[10003];

int main(int argc, char *argv[]) {
	int i, t, l, len, n;
	scanf("%s %s", &a, &b);
	l = strlen(a)-1;
	len = strlen(b)-1;
	n = (l<=len)? l : len;
	for(i=0;i<=n;i++){
		t = a[l-i]-'0'+b[len-i]-'0';
		t += c[i];
		c[i] = t%10;
		c[i+1] += t/10;
	}
	for(;i<=l;i++){
		t = a[l-i]-'0';
		t += c[i];
		c[i] = t%10;
		c[i+1] += t/10;
	}
	for(;i<=len;i++){
		t = b[len-i]-'0';
		t += c[i];
		c[i] = t%10;
		c[i+1] += t/10;
	}
	if(c[i]==0) i-=1;
	for(;i>-1;i--){
		printf("%d", c[i]);
	}
	return 0;
}
