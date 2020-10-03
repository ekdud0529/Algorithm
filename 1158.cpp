#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	cout << "<";
	n--;
	while(n--){
		for(int i=0; i<m-1; i++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front() <<", ";
		q.pop();
	}
	
	cout << q.front() << ">";
	
	return 0;
}
