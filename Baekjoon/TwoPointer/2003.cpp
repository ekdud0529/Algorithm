#include <iostream>
#include <vector>
using namespace std;

int input[10000];
int n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	int ptr1 = 0, ptr2 = 0;
	int cnt = 0;
	int sum = input[ptr1];

	while (ptr1 <= ptr2 && ptr2 < n)
	{
		if (sum == m)
			cnt++;
		if (sum <= m)
		{
			sum += input[++ptr2];
		}
		else if (sum > m)
		{
			sum -= input[ptr1];
			ptr1++;
			if (ptr1 > ptr2)
			{
				ptr2 = ptr1;
				sum = input[ptr1];
			}
		}
	}
	cout << cnt;
	return 0;
}
