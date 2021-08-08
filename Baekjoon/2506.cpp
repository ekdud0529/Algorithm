#include <bits/stdc++.h>
using namespace std;

int n[101];
int main(int argc, char** argv) {
	int i, t, a=0, b=1;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n[i]);
	}
	for(i=0;i<t;i++){
		if(n[i]==1){
			if(n[i-1]==1){
				b++;
				a+=b;
			}
			else{
				b=1;
				a+=1;
			}
		}
	}
	printf("%d", a);
	return 0;
}
