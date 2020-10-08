#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, cnt=0;
	cin >> n;
	for(int i=5; i<=n; i*=5){
		cnt += n/i;
	}
	cout << cnt;
	
	return 0;
}
