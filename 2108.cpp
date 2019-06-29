#include <bits/stdc++.h>
using namespace std;

int n[500001], b[500001], c[500001];

int main(int argc, char** argv) {
	int i, num, k, t=0, m=0, a;
	scanf("%d", &num);
	for(i=0;i<num;i++){
		scanf("%d", &n[i]);
		t += n[i];
	}
	if(num==1){
		printf("%d\n", n[0]);
		printf("%d\n", n[0]);
		printf("%d\n", n[0]);
		printf("%d\n", 0);
	}
	else{
		sort(n, n+num);
		for(i=0;i<num;i++){
			for(k=i;k<num;k++){
				a = i;
				if(n[i]==n[k]){
					b[i]++;
				}
				else{
					i=k-1;
					break;
				}
			}
			if(m<b[a])m = b[a];
			if(k==num) break;
		}
		k=0;
		for(i=0;i<num;i++){
			if(m==b[i]){
				c[k] = n[i];
				k++;
			}
		}
		
		if(t/m>0) printf("%d\n", (int)((float)t/num+0.5));
		else printf("%d\n", (int)((float)t/num-0.5));
		printf("%d\n", n[num/2]);	
		if(k>1) printf("%d\n", c[1]);
		else printf("%d\n", c[0]);		
		printf("%d", n[num-1]-n[0]);	
	}
	return 0;
}
