#include <bits/stdc++.h>
using namespace std;

void mk_num(string arr, deque<int> *num)
{
	int n = 0;
	for(int i=0; i<arr.size(); i++)
	{
		if(arr[i] == '[') continue;
		else if(arr[i] == ',' || arr[i] == ']')
		{
			if(n > 0) (*num).push_back(n);
			n = 0;
		}
		else
		{
			n = n*10 + (arr[i]-'0');
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while(t--)
	{
		string str, arr;
		int len;
		deque<int> dq;
		bool check = true, reverse=true;
		cin >> str >> len >> arr;
		
		mk_num(arr, &dq);
		
		for(int i=0; i<str.size(); i++)
		{
			if(str[i] == 'R') reverse = !(reverse);
			if(str[i] == 'D')
			{
				if(dq.size() == 0)
				{
					cout << "error\n";
					check = false;
					break;
				}
				else
				{
					if(reverse) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		
		if(check)
		{
			cout << "[";
			while(dq.size())
			{
				if(reverse)
				{
					cout << dq.front();
					if(dq.size() > 1) cout << ",";
					dq.pop_front();
				}
				else
				{
					cout << dq.back();
					if(dq.size() > 1) cout << ",";
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}
