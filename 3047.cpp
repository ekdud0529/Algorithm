#include <bits/stdc++.h>
using namespace std;
int num[4];

int main() {
	int i, j, k, t, u,m,p;
	char a, b, c;
	for(i=0;i<3;i++){
		scanf("%d ", &num[i]);
	}
	for(j=0;j<3;j++){
		for(k=2;k>0+j;k--){
			if(num[k-1]>num[k]){
				t = num[k];
				num[k] = num[k-1];
				num[k-1] = t;
			}
			
		}
	}
	scanf("%c%c%c", &a, &b, &c);
	u = a-'A';
	m = b-'A';
	p = c-'A';	
	printf("%d %d %d", num[u], num[m], num[p]);
	return 0;
}
