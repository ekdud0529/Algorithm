#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	cnt[1] = 1;
	cnt[2] = 2;
	
	for(int i=3; i<=n; i++)
	{
		cnt[i] = (cnt[i-2] + cnt[i-1]) % 15746;
	}

	cout << cnt[n];
	return 0;
}
