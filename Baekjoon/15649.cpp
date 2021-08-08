#include <bits/stdc++.h>
using namespace std;

bool ch[9];
int cnt=0, n, m, num[9];

void f(int pos){
	if(cnt == m){
		for(int i=0; i<cnt ;i++){
			printf("%d ", num[i]);
		}
		printf("\n");
	}
	for(int i=1; i<=n; i++){
		if(!ch[i]){
			ch[i] = true;
			num[pos] = i;
			cnt++;
			f(pos+1);
			ch[i] = false;
			cnt--;
		}
	}
}

int main(int argc, char** argv) {
	scanf("%d %d", &n, &m);
	f(0);
	return 0;
}
