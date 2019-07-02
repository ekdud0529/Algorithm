#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int h, m, p, k;
	scanf("%d %d", &h, &m);
	scanf("%d", &p);
	k = m+p;
	if(k>=60){
		if(h+(k/60)>=24){
			printf("%d %d", h+k/60-24, k%60);
		}
		else{
			printf("%d %d", h+k/60, k%60);
		}
	}
	else{
		printf("%d %d", h, k);
	}
	return 0;
}
