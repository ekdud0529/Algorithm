#include <bits/stdc++.h>
using namespace std;

int f[31][31];

int main(){
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++){
		int n, m;
		cin >> n >> m;
		
		for(int j=1; j<=n; j++){
			for(int k=j; k<=m; k++){
				if(j==1) f[j][k] = k;
				else if(j==k) f[j][k] = 1;
				else{
					f[j][k] = f[j][k-1] + f[j-1][k-1];
				}
			}
		}
		cout << f[n][m] << "\n";
	}
	
	return 0;
}
