#include <bits/stdc++.h>
using namespace std;

bool check[1000001];
int pm[1000001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int p=0, t, n;
	
	for(int i=2; i<=1000000; i++){
		if(!check[i]){
			pm[p++] = i;
			for(int j=i+i; j<=1000000; j+=i){
				check[j] = true;
			}
		}
	}
	
	cin >> t;
	
	while(t--){
		cin >> n;
		int cnt=0;
		for(int i=0; i<p; i++){
			if(n-pm[i] >= 2 && pm[i] <= n-pm[i]){
				if(!check[n-pm[i]]){
					cnt++;
				}
			}
			else{
				break;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}
