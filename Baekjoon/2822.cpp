#include <bits/stdc++.h>
using namespace std;

int n[9], t[9], m[6];

int main(int argc, char** argv) {
	int  i, a=0, b=0, k;
	for(i=0;i<8;i++){
		scanf("%d", &n[i]);
		t[i]=n[i];
	}
	sort(t, t+8);
	for(i=7;i>2;i--){
		a += t[i];
	}
	printf("%d\n", a);
	for(i=3;i<8;i++){
		for(k=0;k<8;k++){
			if(t[i]==n[k]){
				m[i-3]=k;
			}
		}
	}
	sort(m, m+5);
	for(i=0;i<5;i++){
		printf("%d ", m[i]+1);
	}
	return 0;
}
