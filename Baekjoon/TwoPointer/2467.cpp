#include <iostream>
using namespace std;

int w1, w2;
int value = 2000000001;

void GetMinVal(int mix[])
{
	int a = w1;
	int b = w2;
	int val = value;

	while (a < b)
	{
		val = mix[a] + mix[b];
		if (val == 0 || (abs(val) < abs(value)))
		{
			w1 = a;
			w2 = b;
			value = val;
			if (val == 0) return;
		}
		if (val > 0) b--;
		if (val < 0) a++;
	}
}

int main(void)
{
	int n;
	int mix[100000];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mix[i];
	}
	w1 = 0;
	w2 = n - 1;
	GetMinVal(mix);
	cout << mix[w1] << " " << mix[w2];
	return 0;
}
