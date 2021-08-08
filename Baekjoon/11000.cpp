#include <bits/stdc++.h>
using namespace std;

int cmp(pair<int, int> x, pair<int, int> y){
	if(x.first == y.first) return x.second < y.second;
	return x.first < y.first;
}

int main(int argc, char** argv) {
	int n, cnt=0, s, t;
	scanf("%d", &n);
	vector<pair<int, int> > cs;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n; i++){
		scanf("%d %d", &s, &t);
		cs.push_back(make_pair(s, t));
	}
	sort(cs.begin(), cs.end(), cmp);
	pq.push(cs[0].second);
	for(int i=1; i<n; i++){
		if(pq.top() > cs[i].first) pq.push(cs[i].second);
		else{
			pq.pop();
			pq.push(cs[i].second);
		}	
	}
	printf("%d", pq.size());
	return 0;
}
