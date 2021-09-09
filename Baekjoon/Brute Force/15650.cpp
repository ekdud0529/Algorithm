#include <bits/stdc++.h>
using namespace std;

int a[9], n, m;

void go(int ind, int start){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=start; j<=n; j++){
		a[ind] = j;
		go(ind+1, j+1);
	}
}

int main(){
	cin >> n >> m;
	go(0, 1);
	return 0;
}
