#include <bits/stdc++.h>
using namespace std;

char o[11];

int main(int argc, char** argv) {
	int n, num;
	deque<int> dq;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf(" %s", o);
		if(!strcmp(o, "push_back")){
			scanf("%d", &num);
			dq.push_back(num);
		}
		else if(!strcmp(o, "push_front")){
			scanf("%d\n", &num);
			dq.push_front(num);
		}
		else{
			if(!strcmp(o, "empty")){
				if(dq.empty()) printf("1\n");
				else printf("0\n");
			}
			else if(!strcmp(o, "size")) printf("%d\n", dq.size());
			else if(dq.empty()) printf("-1\n");
			else if(!strcmp(o, "pop_front")){
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else if(!strcmp(o, "pop_back")){
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			else if(!strcmp(o, "front")) printf("%d\n", dq.front());
			else if(!strcmp(o, "back")) printf("%d\n", dq.back());
		}
	}
	return 0;
}
