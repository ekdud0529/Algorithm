#include <bits/stdc++.h>
using namespace std;

int n, m, a[8], cnt[8];

void go(int ind, int num[]){
	if(ind == m){
		for(int i=0; i<ind; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int j=0; j<n; j++){
		if(num[j]>10000) continue;
		if(cnt[j]>0){
			cnt[j]--;
			a[ind] = num[j];
			go(ind+1, num);
			cnt[j]++;
		}
	}
}

int main(){
	cin >> n >> m;
	int num[n];
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	for(int i=0; i<n; i++){
		cnt[i]=1;
		for(int j=i+1; j<n; j++){
			if(num[i] == num[j]){
				cnt[i]++;
				num[j] = 10001;	
			}
		}
	}
	go(0, num);
	return 0;
}
