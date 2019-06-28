#include <bits/stdc++.h>
using namespace std;

int l[10000];

int main(int argc, char** argv) {
	int k, n, i;
	long long lt=1, rt, m, max=0, sum;
	scanf("%d %d", &k, &n);
	for(i=0;i<k;i++){
		scanf("%d", &l[i]);
		sum += l[i];
	}
	rt = sum/n;
	while(rt>=lt){
		sum=0;
		m = (lt+rt)/2;
		for(i=0;i<k;i++){
			sum += l[i]/m;	
		}
		if(sum>=n){
			max = m;
			lt = m+1;
		}
		else rt = m-1;
	}
	printf("%lld", max);
	return 0;
}
