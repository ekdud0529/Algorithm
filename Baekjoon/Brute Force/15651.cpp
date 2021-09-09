#include <bits/stdc++.h>
using namespace std;

int a[9], n, m;;

void go(int ind){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=1; j<=n; j++){
		a[ind] = j;
		go(ind+1);
	}
}

int main(){
	cin >> n >> m;
	go(0);
	
	return 0;
}
