#include <bits/stdc++.h>
using namespace std;

int n;
int num[11];
vector<char> op;
bool used[10];
int op_max = -1000000000, op_min = 100000000;

int calcul(int oper, int a, int b)
{
	switch(op[oper])
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
	}
}

void calc(int index, int result)
{
	if(index == n-1)
	{
		if(op_max < result) op_max = result;
		if(op_min > result) op_min = result;
		return ;
	}
	
	for(int i=0; i<n-1; i++)
	{
		if(used[i]) continue;
		used[i] = true;
		calc(index+1, calcul(i, result, num[index+1]));
		used[i] = false;
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
	}
	for(int i=0; i<4; i++)
	{
		int o;
		cin >> o;
		switch(i)
		{
			case 0:
				for(int j=0; j<o; j++)
					op.push_back('+');
				break;
			case 1:
				for(int j=0; j<o; j++)
					op.push_back('-');
				break;
			case 2:
				for(int j=0; j<o; j++)
					op.push_back('*');
				break;
			case 3:
				for(int j=0; j<o; j++)
					op.push_back('/');
				break;	
		}
	}
	
	calc(0, num[0]);
	cout << op_max << "\n" << op_min;
	return 0;
}
