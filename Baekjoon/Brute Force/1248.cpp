#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int num[21];
char s[55];
int numbers[10];

bool check_sign(int idx)
{
	int index = 0;
	for(int i=0; i<idx; i++)
	{
		index += (n-i);
	}
	char ch = s[index];

	if(ch == '-')
	{
		if(numbers[idx] >= 0) return true;
	}
	else if(ch == '+')
	{
		if(numbers[idx] <= 0) return true;
	}
	else if(ch == '0')
	{
		if(numbers[idx] != 0) return true;
	}
	return false;
}

bool ch_num(int idx_cnt)
{
	int idx = 0;
	for(int i=0; i<cnt; i++)
	{
		int sum = 0;
		int j = idx;
		for(int k=i; k<i+(n-idx); k++)
		{
			if(j > idx_cnt) break;
			sum += numbers[j++];
			if(s[k] == '-' && sum >= 0) return false;
			if(s[k] == '+' && sum <= 0) return false;
			if(s[k] == '0' && sum != 0) return false;
		}
		idx++;
		i += (n-idx);
	}
	return true;
}

bool mk_a(int index)
{
	if(index == n)
	{
		if(ch_num(cnt))
		{
			return true;
		}
		return false;
	}
	bool ch = false;
	for(int i=0; i<21; i++)
	{
		numbers[index] = num[i];
		if(check_sign(index)) continue;
		if(!ch_num(index)) continue;
		ch = mk_a(index + 1);
		if(ch) return true;
	}
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a = -10;
	for(int i=0; i<21; i++)
	{
		num[i] = a;
		a++;
	}

	cin >> n;
	cnt = n*(n+1) / 2;
	for(int i=0; i<cnt; i++)
	{
		cin >> s[i];
	}

	check_sign(cnt);
	mk_a(0);
	for(int i=0; i<n; i++)
	{
		cout << numbers[i];
		if(i < n-1) cout << " ";
	}
	return 0;
}
