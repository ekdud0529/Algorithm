#include <bits/stdc++.h>
using namespace std;

int c[100];

int main(int argc, char** argv) {
	int n, m, sum;
	scanf("%d %d", &n, &m);
	priority_queue<int, vector<int>, less<int> > pq;
	for(int i=0; i<n; i++) scanf("%d", &c[i]);
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				sum = c[i]+c[j]+c[k];
				if(sum<=m) pq.push(sum);
			}
		}
	}
	printf("%d", pq.top());
	return 0;
}
