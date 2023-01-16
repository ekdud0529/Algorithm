#include <iostream>
#include <cmath>
using namespace std;

int getMinMove(int x, int y)
{
	int minMove = y - x;
	int sqr = sqrt(minMove);

	minMove = sqr * 2 - 1;
	if (y - x - (sqr * sqr) != 0)
	{
		if (y - x - (sqr * sqr) <= sqr) minMove += 1;
		if (y - x - (sqr * sqr) > sqr) minMove += 2;
	}
	return (minMove);
}

int main(int argc, char** argv)
{
	int t, x, y;

	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		cout << getMinMove(x, y) << "\n";
	}
	return 0;
}
