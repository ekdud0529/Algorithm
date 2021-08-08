#include <bits/stdc++.h>
using namespace std;

int q[10001];

int main(int argc, char** argv) {
	int a, d, i, front=0, back=0;
	char m[6];
	scanf("%d", &d);
	for(i=0;i<d;i++){
		scanf("%s", m);
		if(strcmp(m,"push")==0){
			scanf("%d", &a);
			q[back] = a;
			back++;
		}
		else if(strcmp(m,"pop")==0){
			if(front!=back){
				printf("%d\n", q[front]);
				q[front] = 0;
				front++;
			}
			else printf("-1\n");
		}
		else if(strcmp(m,"size")==0){
			printf("%d\n", back-front);
		}
		else if(strcmp(m,"empty")==0){
			if(front==back) printf("1\n");
			else printf("0\n");
		}
		else if(strcmp(m,"front")==0){
			if(front==back) printf("-1\n");
			else printf("%d\n", q[front]);
		}
		else{
			if(strcmp(m,"back")==0){
				if(front==back) printf("-1\n");
				else printf("%d\n", q[back-1]);
			}
		}
	}
	return 0;
}
