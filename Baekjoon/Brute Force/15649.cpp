#include <bits/stdc++.h>
using namespace std;

bool num[9];
int a[9];

void go(int ind, int n, int m){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=1; j<=n; j++){
		if(num[j]) continue;
		a[ind] = j;
		num[j] = true;
		go(ind+1, n, m);
		num[j] = false;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	
	return 0;
}
