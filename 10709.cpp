#include <bits/stdc++.h>
using namespace std;

char t[101];
int s[101];

int main(int argc, char** argv) {
	int h, w, i, k, j, a;
	scanf("%d %d", &h, &w);
	for(i=0;i<h;i++){
		a = 0;
		scanf("%s", &t);
		for(k=0;k<w;k++){
			if(t[k]=='c'){
				s[k] = 0;
				a++;
			}
			else if(a!=0) s[k] = s[k-1]+1;
			else s[k] = -1;
		}
		for(j=0;j<w;j++){
			printf("%d ", s[j]);
		}
		printf("\n");
	}
	return 0;
}
