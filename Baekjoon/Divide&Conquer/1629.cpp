#include <bits/stdc++.h>
using namespace std;

long long divideC(int a, int b, int c)
{
	if (b == 1) return (a % c);
	
	long long mul = divideC(a, b/2, c);
	
	if(!(b % 2))
		return (mul * mul % c);
	else
		return (mul * mul % c * a % c);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a == 1 || b == 1 || (a%c) == 1) cout << a % c;
	else
	{
		cout << divideC(a % c, b, c);
	}
	return 0;
}
