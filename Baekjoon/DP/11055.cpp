#include <bits/stdc++.h>
using namespace std;

int num [1000], dp[1000];

int main(){
	int n, sum=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	for(int i=0; i<n; i++){
		dp[i] = num[i];
		for(int j=0; j<i; j++){
			if(num[i]>num[j] && dp[j]+num[i]>dp[i]){
				dp[i] = dp[j] + num[i];
			}
		}
		if(sum < dp[i]) sum = dp[i];
	}
	cout << sum;
	
	return 0;
}
