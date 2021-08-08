#include <bits/stdc++.h>
using namespace std;

int n[10], t[10];

int main(int argc, char** argv) {
	int i, k;
	for(i=0;i<9;i++){
		scanf("%d", &n[i]);
		t[i]=n[i];
	}
	sort(t, t+9);
	for(k=0;k<9;k++){
		if(t[8]==n[k]){
			break;
		}
	}
	printf("%d\n%d", n[k], k+1);
	return 0;
}
