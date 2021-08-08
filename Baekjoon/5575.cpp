#include <bits/stdc++.h>
using namespace std;

int t[7], s[4];

int main(int argc, char** argv) {
	int i, n;
	for(i=0;i<3;i++){
		scanf("%d %d %d %d %d %d", &t[0], &t[1], &t[2], &t[3], &t[4], &t[5]);
		s[0] = t[3]-t[0];
		s[1] = t[4]-t[1];
		s[2] = t[5]-t[2];
		if(s[2]<0){
			s[2] += 60;
			s[1] -= 1;
		}
		if(s[1]<0){
			s[1] += 60;
			s[0] -= 1;
		}
		printf("%d %d %d\n", s[0], s[1], s[2]);
	}
	return 0;
}
