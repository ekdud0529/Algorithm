#include <bits/stdc++.h>
using namespace std;

map<string, int> str_poketmon;
map<int, string> int_poketmon;
int mk_num(string str)
{
	int num = 0;
	for(int i=0; i<str.size(); i++)
	{
		num = num*10 + (str[i]-'0');
	}
	return num;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		string str;
		cin >> str;
		str_poketmon.insert({str, i+1});
		int_poketmon.insert({i+1, str});
	}
	
	string str;
	for(int i=0; i<m; i++)
	{	
		cin >> str;
		if('0' <= str[0] && str[0] <= '9')
		{
			int num = mk_num(str);
			cout << int_poketmon[num] << "\n";
		}
		else
		{
			cout << str_poketmon[str] << "\n";
		}
	}
	return 0;
}
