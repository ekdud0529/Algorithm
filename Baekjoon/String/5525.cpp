#include <bits/stdc++.h>
using namespace std;

vector<int> mk_table(string search)
{
	int size = search.size();
	vector<int> table(size, 0);
	int j = 0;
	for(int i=1; i<size; i++)
	{
		while(j > 0 && search[j] != search[i])
		{
			j = table[j - 1];
		}
		if(search[j] == search[i])
		{
			table[i] = ++j;
		}
	}
	return table;
}

int kmp(string str, string search)
{
	vector<int> table = mk_table(search);
	int size = str.size();
	int j = 0;
	int cnt = 0;
	
	for(int i=0; i<size; i++)
	{
		while(j>0 && str[i] != search[j])
		{
			j = table[j - 1];
		}
		if(str[i] == search[j])
		{
			if(j == search.size() - 1)
			{
				cnt++;
				j = table[j];
			}
			else j++;
		}
	}
	return cnt;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	string search = "I";
	int n, m;
	
	cin >> n >> m >> str;
	while(n--)
	{
		search += "OI";
	}
	
	int cnt = kmp(str, search);
	
	cout << cnt;
	
	return 0;
}
