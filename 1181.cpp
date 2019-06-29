#include <bits/stdc++.h>
using namespace std;

struct z{
	char s[51];
	int x;
};

struct z t[20001];

bool cmp(const z &a, const z &b){
	if(a.x==b.x){
		int i;
		for(i=0;i<a.x;i++){
			if(a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
		}
	}
	return a.x<b.x;
}

int main(int argc, char** argv) {
	int n, i, k, c;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", &t[i].s);
		t[i].x = strlen(t[i].s);
	}
	stable_sort(t, t+n, cmp);
	for(i=0;i<n;i++){
		if(strcmp(t[i].s, t[i+1].s)) printf("%s\n", t[i].s);
	}
	return 0;
}
