#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, size;
	scanf("%d", &n);
	queue<int > q;
	for(int i=1; i<=n; i++) q.push(i);
	while(q.size()!=1){
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d", q.front());
	return 0;
}
