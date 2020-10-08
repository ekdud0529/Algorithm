#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	int min;
	if(a<=b) min = a;
	else min = b;
	
	for(int i=min; i>0; i--){
		if(a%i == 0 && b%i == 0) return i;
	}
	return 1;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, t;
	cin >> n;
	
	while(n--){
		long long cnt = 0;
		int a[101];
		cin >> t;
	
		for(int i=0; i<t; i++){
			cin >> a[i];
		}
		for(int i=0; i<t-1; i++){
			for(int j=i+1; j<t; j++){
				cnt += gcd(a[i], a[j]);
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}
