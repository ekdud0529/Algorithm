#include <bits/stdc++.h>
using namespace std;

queue<int> num;
queue<char> op;

void mk_num(string s)
{
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '+' || s[i] == '-')
		{
			op.push(s[i]);
		}
		else
		{
			int n = 0;
			while('0' <= s[i] && s[i] <='9')
			{
				n = n*10 + (s[i] - '0');
				i++;
			}
			num.push(n);
			i--;
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	
	mk_num(str);
	
	int min = num.front();
	num.pop();
	while(!num.empty())
	{
		int n = num.front();
		int o = op.front();
		num.pop();
		op.pop();
		
		if(o == '-')
		{
			min -= n;
			while(op.front() == '+')
			{
				min -= num.front();
				op.pop();
				num.pop();
			}
		}
		else
		{
			min += n;
		}
	}
	cout << min;
	
	return 0;
}
