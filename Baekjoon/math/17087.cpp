#include <bits/stdc++.h>
using namespace std;

int br[100001];

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, s;
	cin >> n >> s;
	
	for(int i=0; i<n; i++){
		cin >> br[i];
		if(br[i]>s) br[i] -= s;
		else br[i] = s-br[i];
	}
	
	int max = br[0];
	for(int i=1; i<n; i++){
		max = gcd(max, br[i]);
	}
	
	cout << max;
	
	return 0;
}
