#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> nge(n);
	stack<int> s;
	for(int i=0; i<n; i++) cin >> a[i];
	
	s.push(0);
	for(int i=1; i<n; i++){
		if(s.empty()){
			s.push(i);
		}
		while(!s.empty() && a[s.top()] < a[i]){
			nge[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	
	while(!s.empty()){
		nge[s.top()] = -1;
		s.pop();
	}
	
	for(int i=0; i<n; i++){
		cout << nge[i] << ' ';
	}
	return 0;
}
