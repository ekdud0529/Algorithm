#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<string> command;
vector<int> num;
stack<int> st;
#define MAXNUM 1000000000

void makeClear()
{
	command.erase(command.begin(), command.end());
	num.erase(num.begin(), num.end());
	while (!st.empty())
		st.pop();
}

bool Program(int number)
{
	int index = 0;

	st.push(number);
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == "DUP")
		{
			if (st.empty())
				return false;
			st.push(st.top());
		}
		else if (command[i] == "POP")
		{
			if (st.empty())
				return false;
			st.pop();
		}
		else if (command[i] == "INV")
		{
			if (st.empty())
				return false;
			int digit = st.top();
			st.pop();
			st.push(-digit);
		}
		else if (command[i] == "NUM")
		{
			st.push(num[index++]);
		}
		else if (command[i] == "SWP")
		{
			if (st.empty())
				return false;
			int n1 = st.top();
			st.pop();
			if (st.empty())
				return false;
			int n2 = st.top();
			st.pop();
			st.push(n1);
			st.push(n2);
		}
		else if (command[i] == "ADD")
		{
			if (st.empty())
				return false;
			long long n1 = st.top();
			st.pop();

			if (st.empty())
				return false;
			n1 += st.top();
			st.pop();

			if (n1 > MAXNUM || n1 < -MAXNUM)
				return false;
			st.push((int)n1);
		}
		else if (command[i] == "SUB")
		{
			if (st.empty())
				return false;
			long long n1 = st.top();
			st.pop();
			if (st.empty())
				return false;
			long long n2 = st.top();
			st.pop();
			n1 = n2 - n1;
			if (n1 > MAXNUM || n1 < -MAXNUM)
				return false;
			st.push((int)n1);
		}
		else if (command[i] == "MUL")
		{
			if (st.empty())
				return false;
			long long n1 = st.top();
			st.pop();
			if (st.empty())
				return false;
			n1 *= st.top();
			st.pop();
			if (n1 > MAXNUM || n1 < -MAXNUM)
				return false;
			st.push((int)n1);
		}
		else if (command[i] == "DIV")
		{
			int cnt = 0;
			if (st.empty())
				return false;
			int n1 = st.top();
			if (n1 < 0) cnt++;
			st.pop();
			if (n1 == 0)
				return false;

			if (st.empty())
				return false;
			int n2 = st.top();
			if (n2 < 0) cnt++;
			st.pop();

			n1 = abs(n2 / n1);
			if (cnt == 1)
				n1 = -n1;
			if (n1 > MAXNUM || n1 < -MAXNUM)
				return false;
			st.push((int)n1);
		}
		else if (command[i] == "MOD")
		{
			int cnt = 0;
			if (st.empty())
				return false;
			long long n1 = st.top();
			if (n1 < 0) cnt++;
			st.pop();
			if (n1 == 0)
				return false;

			if (st.empty())
				return false;
			long long n2 = st.top();
			if (n2 < 0) cnt++;
			st.pop();

			n1 = n2 % n1;
			if (n1 > MAXNUM || n1 < -MAXNUM)
				return false;
			st.push((int)n1);
		}
	}
	return true;
}

int main()
{
	while (1)
	{
		string str;

		makeClear();

		cin >> str;
		if (str == "QUIT")
			break;
		while (1)
		{
			if (str == "END") break;
			else if (str == "NUM")
			{
				int digit;
				cin >> digit;
				num.push_back(digit);
			}
			command.push_back(str);
			cin >> str;
		}

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int num;

			cin >> num;
			bool check = Program(num);
			if (!check || st.size() != 1)
			{
				cout << "ERROR\n";
				while (!st.empty())
					st.pop();
				continue;
			}
			cout << st.top() << "\n";
			while (!st.empty())
				st.pop();
		}
		cout << "\n";
	}
	return 0;
}
