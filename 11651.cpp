#include <bits/stdc++.h>
using namespace std;

struct z{
	int x, y;
};

struct z t[100001];

bool cmp(const z &a, const z &b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

int main(int argc, char** argv) {
	int n, k, i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &t[i].x, &t[i].y);
	}
	sort(t, t+n, cmp);
	for(i=0;i<n;i++){
		printf("%d %d\n", t[i].x, t[i].y);
	}
	return 0;
}
