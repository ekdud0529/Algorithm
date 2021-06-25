#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		int n, m;
		int imp[100], cnt=1, check=1;
		queue<int> doc, q;
		cin >> n >> m;
		
		for(int j=0; j<n; j++){
			doc.push(j);
			cin >> imp[j];
			q.push(imp[j]);
		}
		
		sort(imp, imp+n);
		
		while(!q.empty()){
			if(q.front() == imp[n-check]){
				if(doc.front() == m){
					cout << cnt << "\n";
					break;
				}
				else{
					doc.pop();
					q.pop();
					cnt++;
					check++;
				}
			}
			else{
				q.push(q.front());
				doc.push(doc.front());
				q.pop();
				doc.pop();
			}
		}
	}
	return 0;
}

