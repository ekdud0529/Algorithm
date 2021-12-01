#include <bits/stdc++.h>
using namespace std;

map<string, string> site;

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		string str, pwd;
		cin >> str >> pwd;
		site.insert({str, pwd});
	}
	for(int i=0; i<m; i++)
	{
		string find;
		cin >> find;
		cout << site[find] << "\n";
	}
	return 0;
}
