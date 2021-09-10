#include <bits/stdc++.h>
using namespace std;

int n, m, a[8];

void go(int ind, int num[], int start){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=start; j<n; j++){
		a[ind] = num[j];
		go(ind+1, num, j);
	}
}

int main(){
	cin >> n >> m;
	int num[n];
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	go(0, num, 0);
	
	return 0;
}
