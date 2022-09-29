#include <iostream>
#include <sstream>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int cnt = 0;

	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && i != 0)
		{
			cnt++;
		}
	}
	if (s[s.size() - 1] != ' ')
		cnt++;
	cout << cnt;
	return (0);
}
