#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b != 0)
		return gcd(b, a % b);
	return (a);
}

int main()
{
	int a1, b1, a2, b2;

	cin >> a1 >> b1;
	cin >> a2 >> b2;
	
	a1 *= b2;
	a2 *= b1;
	a1 += a2;
	b1 *= b2;
	
	cout << a1 / gcd(a1, b1) << " " << b1 / gcd(a1, b1);

	return 0;
}
