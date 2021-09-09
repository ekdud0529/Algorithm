#include <bits/stdc++.h>
using namespace std;

bool num[9];
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
		if(num[j]) continue;
		a[ind] = j;
		num[j] = true;
		go(ind+1, j+1);
		num[j] = false;
	}
}

int main(){
	cin >> n >> m;
	go(0, 1);
	return 0;
}
