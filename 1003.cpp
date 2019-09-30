#include <bits/stdc++.h>
using namespace std;

struct f{
	int x, y;
};

f fi[41];

int main(int argc, char** argv) {
	int t, n, i, cnt0, cnt1;
	fi[0].x=1; fi[0].y=0;
	fi[1].x=0; fi[1].y=1;
	for(i=2;i<=40;i++){
		fi[i].x = fi[i-1].x + fi[i-2].x;
		fi[i].y = fi[i-1].y + fi[i-2].y;
	}
	scanf("%d", &t);		
	while(t--){
		scanf("%d", &n);
		printf("%d %d\n", fi[n].x, fi[n].y);
	}
	return 0;
}
