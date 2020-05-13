#include <bits/stdc++.h>
using namespace std;

char n[6];

int main(int argc, char *argv[]) {
	int check=0;
	while(1){
		scanf(" %s", n);
		if(n[0]=='0') break;
		int size = strlen(n), s=size/2;
		for(int i=0; i<s; i++){
			if(n[i]!=n[size-i-1]) check=1;
		}
		if(check==0) printf("yes\n");
		else printf("no\n");
		check = 0;
	}
	return 0;
}
