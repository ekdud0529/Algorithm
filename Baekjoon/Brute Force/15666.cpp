#include <bits/stdc++.h>
using namespace std;

int n, m, a[8], cnt;

void go(int ind, int num[], int start){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=start; j<cnt; j++){
		if(a[j] > 10000) continue;
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
	for(int i=0; i<n; i++){
		if(num[i] > 10000) continue;
		cnt++;
		for(int j=i+1; j<n; j++){
			if(num[i] == num[j]){
				num[j] = 10001;	
			}
		}
	}
	sort(num, num+n);
	go(0, num, 0);
	return 0;
}
