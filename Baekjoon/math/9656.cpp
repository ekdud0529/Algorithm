#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, cnt=0;
	cin >> n;
	n%=2;
	if(n%2==0) printf("SK");
	else printf("CY");
	
	return 0;
}
