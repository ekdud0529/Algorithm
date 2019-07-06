#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a;
	scanf("%d", &a);
	if(a%4==0&&a%100!=0){
		printf("1");
	}
	else{
		if(a%400==0){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	return 0;
}
