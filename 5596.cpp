#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, n, min=0, man=0;
	for(i=0;i<8;i++){
		scanf("%d", &n);
		if(i<4) min += n;
		else man += n;
	}
	if(min>=man) printf("%d", min);
	else if(min<man) printf("%d", man);
	return 0;
}
