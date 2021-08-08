#include <bits/stdc++.h>
using namespace std;

int n, m, treeh[1000000], height;

int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> treeh[i];
	}
	
	sort(treeh, treeh+n);
	
	int l=1, r=treeh[n-1], check=treeh[n-1];
	long long sum;
	
	while(l<=r){
		sum=0;
		height = (l+r)/2;
		
		for(int j=n-1; j>=0; j--){
			if(treeh[j] > height){
				sum += treeh[j]-height;
			}
			else{
				break;
			}
		}
		
		if(sum > m){
			check = height;
			l = height+1;
		}
		
		else if(sum < m){
			r = height-1;
		}
		
		else{
			break;
		}
	}
	height = (sum>=m)?height:height-1;
	cout << height;
	
	return 0;
}
