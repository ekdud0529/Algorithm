#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int div = 2;
	while(n > 1)
	{
		if(n%div == 0)
		{
			cout << div <<"\n";
			n /= div;
		}
		else div++;
	}
	return 0;
}
