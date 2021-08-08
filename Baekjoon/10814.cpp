#include <bits/stdc++.h>
using namespace std;

struct z{
	int x;
	char s[101];
};

struct z t[100001];

bool cmp(const z &a, const z &b){
	return a.x<b.x;
}

int main(int argc, char** argv) {
	int n, k, i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %s", &t[i].x, &t[i].s);
	}
	stable_sort(t, t+n, cmp);
	for(i=0;i<n;i++){
		printf("%d %s\n", t[i].x, t[i].s);
	}
	return 0;
}
