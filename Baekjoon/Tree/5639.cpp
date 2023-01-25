#include <iostream>
using namespace std;

int node[10001];

void PostOrder(int start, int end)
{
	int i;

	if (start >= end) return;
	for (i = start + 1; i < end; i++)
	{
		if (node[start] < node[i]) break;
	}
	PostOrder(start + 1, i);
	PostOrder(i, end);
	cout << node[start] << "\n";
}

int main(void)
{
	int num;
	int cnt = 0;

	while (cin >> num)
	{
		node[cnt++] = num;
	}
	PostOrder(0, cnt);
	return 0;
}
