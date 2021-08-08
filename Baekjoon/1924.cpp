#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int m, d, i;
	scanf("%d %d", &m, &d);
	for(i=1;i<m;i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			d+=31;
		}
		else if(i==2) d+=28;
		else d+=30;
	}
	switch(d%7){
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		default:
			printf("SAT");
	}
	return 0;
}
