#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	char str[1000001];
	int cnt=1, i;
	cin.getline(str, 1000000);
	for(i=0; str[i]!=NULL; i++){
		if(str[i]==' ') cnt++;
	}
	if(str[i-1]==' ') cnt--;
	if(str[0]==' ') cnt--;
	printf("%d", cnt);
	return 0;
}
