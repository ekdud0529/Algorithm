#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--;
		y--;
		
		bool check = false;
		
		for(int k=x; k<(n*m); k+=m){
			if(k%n == y){
				check = true;
				cout << k+1 << "\n";
				break;
			}
		}
		
		if(!check) cout << -1 << "\n";
	}
	
	return 0;
}
