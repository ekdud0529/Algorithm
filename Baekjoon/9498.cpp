#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, k;
	scanf("%d", &a);
	k = a / 10;
	switch(k){
		case 10:
			printf("A");
			break;
		case 9:
			printf("A");
			break;
		case 8:
			printf("B");
			break;
		case 7:
			printf("C");
			break;
		case 6:
			printf("D");
			break;
		default:
			printf("F");
	}
	return 0;
}
