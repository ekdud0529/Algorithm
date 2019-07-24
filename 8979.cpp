#include <bits/stdc++.h>
using namespace std;

struct num{
	int n;
	int g;
	int s;
	int b;
};

struct num c[1001];

bool cmp(const num &a, const num &e){
	if(a.g!=e.g) return a.g>e.g;
	else{
		if(a.g==e.g){
			if(a.s!=e.s) return a.s>e.s;
			else{
				if(a.b!=e.b) return a.b>e.b;
			}
		}
	}
}

int main(int argc, char** argv) {
	int n, i, k, r=0, cnt=0;
	scanf("%d %d", &n, &k);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d", &c[i].n, &c[i].g, &c[i].s, &c[i].b);
	}
	sort(c, c+n, cmp);
	for(i=0;i<n;i++){
		if(c[i-1].g!=c[i].g||c[i-1].s!=c[i].s||c[i-1].b!=c[i].b) r++;
		else if(c[i-1].g==c[i].g&&c[i-1].s==c[i].s&&c[i-1].b==c[i].b) cnt++;
		if(c[i-1].g!=c[i].g||c[i-1].s!=c[i].s||c[i-1].b!=c[i].b){
			r += cnt;
			cnt = 0;
		}
		if(c[i].n==k){
			printf("%d", r);
			break;
		}
	}
	return 0;
}
