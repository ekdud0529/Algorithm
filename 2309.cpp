#include <bits/stdc++.h>
using namespace std;

int n[9];

int main(int argc, char** argv) {
	int i, j, k, cnt=0, min, tmp=0;
	for(i=0;i<9;i++){
		scanf("%d", &n[i]);
		cnt+=n[i];
	}
	for(i=0;i<8;i++){
		min=i; tmp = n[i];
		for(k=i+1;k<9;k++){
			if(n[min]>n[k]) min=k;
		}
		tmp = n[i];
		n[i] = n[min];
		n[min] = tmp;
	}
	for(i=0;i<8;i++){
		for(k=i+1;k<9;k++){
			tmp = cnt;
			tmp -= n[i]+n[k];
			if(tmp==100) break;
		}
		if(tmp==100) break;
	}
	for(j=0;j<9;j++){
		if(j==i||j==k) continue;
		else printf("%d\n", n[j]);
	}
	return 0;
}
