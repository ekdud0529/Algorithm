#include <iostream>
using namespace std;

int n ,m;
int sub[1000001];

int find(int a)
{
	if (a == sub[a])
		return (a);
	return (sub[a] = find(sub[a]));
}

void Union(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);
	sub[bRoot] = aRoot;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int f, a, b;

	cin >> n >> m;
	while(n >= 0)
	{
		sub[n] = n;
		n--;
	}
	while (m--)
	{
		cin >> f >> a >> b;
		if (f == 1)
		{
			if(find(a) != find(b))
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else
		{
			Union(a, b);
		}
	}
	return (0);
}
