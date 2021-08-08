#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	i = (v-b)/(a-b);
	if((v-b)%(a-b)!=0){
		i += 1;
	}
	printf("%d", i);
	return 0;
}
