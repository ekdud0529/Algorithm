#include <bits/stdc++.h>
using namespace std;

char candy[50][50];

int count(int n){
	int max=0;
	for(int i=0; i<n; i++){
		int cnt=1;
		for(int j=0; j<n-1; j++){
			if(candy[i][j] == candy[i][j+1] && j+1<n){
				cnt++;
			}
			else cnt=1;
			if(cnt > max) max = cnt;
		}
	}
	
	for(int i=0; i<n; i++){
		int cnt=1;
		for(int j=0; j<n-1; j++){
			if(candy[j][i] == candy[j+1][i] && j+1<n){
				cnt++;
			}
			else cnt=1;
			if(cnt > max) max = cnt;
		}
	}
	
	return max;
}

int main(){
	int n, ans=0;
	cin >> n;
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			cin >> candy[i][j];
		}
	}
	
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			if(j+1 < n){
				swap(candy[i][j], candy[i][j+1]);
				int cnt = count(n);
				ans = max(cnt, ans);
				swap(candy[i][j], candy[i][j+1]);
			}
			
			if(i+1 < n){
				swap(candy[i][j], candy[i+1][j]);
				int cnt = count(n);
				ans = max(cnt, ans);
				swap(candy[i][j], candy[i+1][j]);
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
