#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int t, c[6];
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		double d, max, min;
		for(int j=0; j<6; j++) scanf("%d", &c[j]);
		max = (c[2]<=c[5])? c[5]:c[2];
		min = (c[2]<=c[5])? c[2]:c[5];
		d = sqrt(pow(c[3]-c[0],2)+pow(c[4]-c[1],2));
		if(d==0&&c[2]==c[5]) printf("-1\n");
		else if(c[2]+c[5]<d) printf("0\n");
		else if(c[2]+c[5]==d || min+d==max) printf("1\n");
		else if(abs(c[2]-c[5])<d && d<(c[2]+c[5])) printf("2\n");
		else printf("0\n");
	}
	return 0;
}
