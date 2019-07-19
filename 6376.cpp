#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	double i, a = 3, p = 2.5, k, j, t = 1;
	printf("n e\n- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(k=1;k<=a;k++){
		t *= k;
	}
	p += 1/t;
	printf("%.0f %.9f\n", a, p);
	a += 1;
	for(i=0;i<6;i++){
		t *= k;
		p += 1/t;
		printf("%.0f %.9f\n", a, p);
		a += 1;
		k +=1;
	}
	return 0;
}
