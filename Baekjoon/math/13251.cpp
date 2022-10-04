#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m;
	int color[50];
	int k;
	int cnt = 0;
	double sum = 0;
	double bunmo = 1;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> color[i];
		cnt += color[i];
	}
	cin >> k;
	for (int i = 0; i < m; i++)
	{
		double tmp = 1;
		for (int j = 0; j < k; j++)
		{
			tmp *= color[i] - j;
		}
		sum += tmp;
	}
	for (int i = 0; i < k; i++)
	{
		bunmo *= (cnt - i);
	}
	cout << setprecision(15) << (sum / bunmo);
	return 0;
}
