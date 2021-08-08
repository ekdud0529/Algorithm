#include <bits/stdc++.h>
using namespace std;

struct z{
	char s[11];
	int k, e, m;
};

struct z t[100001];

bool cmp(const z &a, const z &b){
		if(a.k!=b.k){
			return a.k>b.k;	
		}
		else{
			if(a.e!=b.e) return a.e<b.e;
			else{
				if(a.m!=b.m) return a.m>b.m;
				else{
					int i;
					for(i=0;i<10;i++){
						if(a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
					}
					
				}
			}
		}
}

int main(int argc, char** argv) {
	int n, i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s %d %d %d", &t[i].s, &t[i].k, &t[i].e, &t[i].m);
	}
	stable_sort(t, t+n, cmp);
	for(i=0;i<n;i++){
		printf("%s\n", t[i].s);
	}
	return 0;
}
