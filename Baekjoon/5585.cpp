#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n[] = {500, 100, 50, 10, 5, 1}, num, cnt=0, i;
	scanf("%d", &num);
	num = 1000-num;
	for(i=0;i<6;i++){
		cnt += num/n[i];
		num %= n[i];
		if(num%n[i]==0) break;
	}
	printf("%d", cnt);
	return 0;
}
