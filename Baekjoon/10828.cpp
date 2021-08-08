#include <bits/stdc++.h>
using namespace std;

int s[10001];

int main(int argc, char** argv) {
	int i, a, d, h = 0, l = 0;
	char m[6];
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%s", m);
		if(strcmp(m,"push")==0){
			scanf("%d", &d);
			s[h] = d;
			h++;
		}
		else if(strcmp(m, "pop")==0){
			if(h==l) printf("-1\n");
			else{
				printf("%d\n", s[h-1]);
				s[h-1] = 0;
				h--;
			}
		}
		else if(strcmp(m,"size")==0) printf("%d\n", h-l);
		else if(strcmp(m,"empty")==0){
			if(h==l) printf("1\n");
			else printf("0\n");
		}
		else{
			if(h!=l) printf("%d\n", s[h-1]);
			else printf("-1\n");
		}
	}
	return 0;
}
