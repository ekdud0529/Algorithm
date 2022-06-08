#include <iostream>
#include <stack>
using namespace std;

int top[500000];
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> top[i];

		while (!st.empty())
		{
			if (top[st.top()] >= top[i])
			{
				cout << st.top() + 1 << " ";
				st.push(i);
				break;
			}
			else
			{
				st.pop();
			}
		}
		if (st.empty())
		{
			cout << "0 ";
			st.push(i);
		}
	}
	return 0;
}
