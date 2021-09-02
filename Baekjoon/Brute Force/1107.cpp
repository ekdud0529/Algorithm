#include <bits/stdc++.h>
using namespace std;

bool bnt[10];

int check(int chennel){
	if(chennel == 0){
		if(bnt[chennel]) return 0;
		else return 1;
	}
	int len=0;
	while(chennel > 0){
		if(bnt[chennel % 10]) return 0;
		chennel /= 10;
		len++;
	}
	return len;
}

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		bnt[a] = true;
	}
	int ans = abs(n-100);
	
	for(int i=0; i<=1000000; i++){
		int chennel = i;
		int len = check(chennel);
		if(len > 0){
			int press = abs(chennel-n);
			ans = min(ans, len+press);
		}
	}
	
	cout << ans;
	
	return 0;
}
