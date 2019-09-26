#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, cnt=0;
	scanf("%d", &n);
	n%=2;
	if(n%2==1) printf("SK");
	else printf("CY");
	return 0;
}
