#include<bits/stdc++.h>
using namespace std;

int a[1000], dp[1000];

int main(){
	int n, max=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(a[i]<a[j] && dp[i]<dp[j]+1){
				dp[i]++;
			}
		}
		if(dp[i] > max) max = dp[i];
	}
	cout << max;
	
	return 0;
}
