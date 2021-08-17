#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int cnt=100000;
	if(n%5 == 0) cnt = n/5;
	else{
		for(int i=0; i*5<=n; i++){
			if((n-(5*i))%2 == 0){
				int sum = (n-(5*i))/2 + i;
				if(sum < cnt) cnt = sum;
			}
		}
	}
	
	if(cnt == 100000) cnt = -1;
	cout << cnt;
	
	return 0;
}
