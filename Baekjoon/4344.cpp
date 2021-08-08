#include <bits/stdc++.h>
using namespace std;

int s[1001];

int main(int argc, char** argv) {
	int n, i, k, cnt, t;
	float p;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		t=0; cnt = 0; p=0;
		scanf("%d", &s[0]);
		for(k=1;k<s[0]+1;k++){
			scanf("%d", &s[k]);
			t += s[k];
		}
		p = t/s[0];
		for(k=1;k<s[0]+1;k++){
			if(s[k]>p) cnt++;
		}
		p = (float)cnt*100/(float)s[0];
		printf("%.3f%\n", p);
	}
	return 0;
}
