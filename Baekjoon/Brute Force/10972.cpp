#include <bits/stdc++.h>
using namespace std;

bool check[10001];
bool ch;
int n;
vector<int> num;
vector<int> ans;

bool next_check()
{
	for(int i=0; i<n; i++)
	{
		if(ans[i] != num[i])
		{
			return false;
		}
	}
	return true;
}

bool recurs(int pos)
{
	int i;
	if(!ch) i = num[pos];
	else i = 1;
	
	if(pos == n)
	{
		if(ch) return true;
		if(next_check())
		{
			ch = true;
		}
		return false;
	}
	
	for(; i<=n; i++)
	{
		if(!check[i])
		{
			ans.push_back(i);
			check[i] = true;
			if(recurs(pos + 1))
			{
				return true;
			}
			check[i] = false;
			ans.pop_back();
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int number;
		cin >> number;
		num.push_back(number);
	}
	
	recurs(0);
	
	if(!ans.size())
	{
		cout << "-1";
	}
	else{
		for(int i=0; i<n; i++)
		{
			cout << ans[i];
			if(i < n-1) cout << " ";
		}
	}
	return 0;
}
