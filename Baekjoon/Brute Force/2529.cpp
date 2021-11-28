#include <bits/stdc++.h>
using namespace std;

int n;
long long min_num = 10000000000;
long long max_num = 0;
int numbers[10];
char sign[9];
bool check[10];

long long mk_num()
{
	long long num = 0;
	for(int i=0; i<=n; i++)
	{
		num = num*10 + numbers[i];
	}
	return num;
}

int check_num()
{
	for(int i=0; i<n; i++)
	{
		if(sign[i] == '<')
		{
			if(numbers[i] > numbers[i+1])
			{
				return 0;
			}
		}
		else
		{
			if(numbers[i] < numbers[i+1])
			{
				return 0;
			}
		}
	}
	return 1;
}

void get_num(int cnt)
{
	if(cnt == n+1)
	{
		if(check_num())
		{
			long long num = mk_num();
			if(num < min_num) min_num = num;
			if(num > max_num) max_num = num;
		}
		return ;
	}

	for(int i=0; i<10; i++)
	{
		if(check[i]) continue;
		numbers[cnt] = i;
		check[i] = true;
		get_num(cnt+1);
		check[i] = false;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> sign[i];
	}
	get_num(0);

	long long m = pow(10, n);
	cout << max_num << "\n";
	if(min_num < m)
	{
		cout << "0";
	}
	cout << min_num;
	return 0;
}
