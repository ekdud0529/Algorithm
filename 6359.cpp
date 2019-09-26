#include <bits/stdc++.h>
using namespace std;

bool n[101];

int main(int argc, char** argv) {
	int t, num, i, j, k, cnt;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &num);
		cnt=0;
		for(j=2;j<=num;j++){
			for(k=1;k*j<=num;k++){
				if(n[k*j]==false) n[k*j]=true;
				else n[k*j]=false;
			}
		}
		for(j=1;j<=num;j++) if(n[j]==false) cnt++;
		printf("%d\n", cnt);
		for(k=1;k<=100;k++) n[k]=false;
	}
	return 0;
}
