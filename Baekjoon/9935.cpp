#include <iostream>
#include <stack>
using namespace std;

string str;
string bomb;
stack<char> st;

void rmBomb(void)
{
	string s = "";

	for (int i = bomb.size(); i > 0; i--)
	{
		if (st.empty() || (st.top() != bomb[i - 1]))
		{
			for (int i = s.size(); i > 0; i--)
			{
				st.push(s[i - 1]);
			}
			return;
		}
		if (st.top() == bomb[i - 1])
		{
			s += st.top();
			st.pop();
		}
	}
}

int main(void)
{
	cin >> str >> bomb;
	for (char c : str)
	{
		st.push(c);
		if (c == bomb[bomb.size() - 1])
		{
			rmBomb();
		}
	}
	str = "";
	while (!st.empty())
	{
		str += st.top();
		st.pop();
	}
	if (str == "")
		cout << "FRULA";
	else
	{
		for (int i = str.size(); i > 0; i--)
		{
			cout << str[i - 1];
		}
	}
	return 0;
}
