#include <bits/stdc++.h>
#include <string>
using namespace std;

int n[9];

int main(int argc, char** argv) {
	int i, a=1, b=8;
	for(i=0;i<8;i++){
		scanf("%d", &n[i]);
		if(n[i]==a) a++;
		else if(n[i]==b) b--;
	}
	if(a==9) printf("ascending");
	else if(b==1) printf("descending");
	else printf("mixed");
	return 0;
}
