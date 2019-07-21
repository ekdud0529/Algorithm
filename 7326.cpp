#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, i, x, y, a, b, c, d;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		if(x%2==0){
			c=0;
			a=0;
			b=0;
			d=0;
			while(x>=a){
				d++;
				if(a==x&&b==y){
					printf("%d\n", c);
					break;
				}
				if(d%2!=0) a+=2;
				if(d%2==0) b+=2;
				c += 2;
			}
		}
		else{
			c=1;
			a=1;
			b=1;
			d=0;
			while(x>=a){
				d++;
				if(a==x&&b==y){
					printf("%d\n", c);
					break;
				}
				if(d%2!=0) a+=2;
				if(d%2==0) b+=2;
				c+=2;
			}
		}
		if(a>x) printf("No Number\n");
	}	
	return 0;
}
