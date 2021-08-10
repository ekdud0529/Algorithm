#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	else{
		int r = a%b;
		a = b;
		b = r;
		return gcd(a, b);
	}
}

int main(){
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++){
		int a, b, r, lcm;
		cin >> a >> b;
		
		lcm = gcd(a, b);
		lcm = lcm * (a/lcm) * (b/lcm);
		
		cout << lcm << "\n";
	}	
    return 0;
}
