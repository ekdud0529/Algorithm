#include <bits/stdc++.h>
using namespace std;

bool check[1000001];
int prime[1000001];
int p;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	check[0] = true;
	check[1] = true;
	
	for(int i=2; i*i<=1000000; i++){
		if(!check[i]){
			prime[p++] = i;
			for(int j=i+i; j<=1000000; j+=i){
				check[j] = true;
			}
		}
	}
	
	int n;
	cin >> n;
	while(n){
		for(int i=1; i<p; i++){
			if(!check[n-prime[i]]){
				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				break;
			}
		}
		cin >> n;
	}
	
	return 0;
}
