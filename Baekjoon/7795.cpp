#include <bits/stdc++.h>
using namespace std;

int a[20001], b[20001];

int main(int argc, char** argv) {
	int t, n, m, i, k, cnt, j, c;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &n, &m);
		for(k=0;k<n;k++) scanf("%d", &a[k]);
		sort(a, a+n);
		for(k=0;k<m;k++) scanf("%d", &b[k]);
		sort(b, b+m);
		cnt=0;
		c=0;
		for(k=0;k<n;k++){
			for(j=c;j<m;j++){
				if(a[k]<b[j]||a[k]==b[j]){
					c = j;
					cnt += c;
					break;
				}
				else if(a[k]>b[j]&&j==m-1) cnt+=m;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
