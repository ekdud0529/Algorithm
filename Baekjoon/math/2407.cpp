#include <bits/stdc++.h>
using namespace std;

string c[101][101];

string numAdd(string n, string m)
{
	long long sum = 0;
	string str;
	
	while (!n.empty() || !m.empty() || sum)
	{
		if (!n.empty())
		{
			sum += n.back() - '0';
			n.pop_back();
		}
		if (!m.empty())
		{
			sum += m.back() - '0';
			m.pop_back();
		}
		str.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(str.begin(), str.end());
	return (str);
}

string combination(int n, int m)
{
	if((n == m) || (m == 0))
		return ("1");
	
	string &str = c[n][m];
	if(str != "")
		return (str);
		
	str = numAdd(combination(n-1, m-1), combination(n-1, m));
	return (str);
}

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	cout << combination(n, m);
	return 0;
}
