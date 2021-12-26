#include <bits/stdc++.h>
using namespace std;

bool num[10001];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 1;
	while(n <= 10000)
	{
		int add = n;
		int number = n;
		
		while(add)
		{
			number += add%10;
			add /= 10;
		}
		if(number <= 10000) num[number] = true;
		n++;
	}
	
	for(int i=1; i<=10000; i++)
	{
		if(num[i]) continue;
		cout << i << "\n";
	}
	
	return 0;
}
