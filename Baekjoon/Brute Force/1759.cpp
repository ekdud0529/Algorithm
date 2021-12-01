#include <bits/stdc++.h>
using namespace std;

int l, c;
bool check[26];
vector<char> alpha;
string answer = "";

int check_alpha()
{
	int cnt_vow = 0;
	int cnt_cons = 0;
	for(int i=0; i<answer.size(); i++)
	{
		if(answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' 
			|| answer[i] == 'o' || answer[i] == 'u')
		{
			cnt_vow++;
		}
		else cnt_cons++;
	}
	if((cnt_vow >= 1) && (cnt_cons >= 2))
	{
		return 1;
	}
	return 0;
}

void get_pwd(int index)
{
	if(answer.size() == l && check_alpha())
	{
		for(int i=0; i<answer.size(); i++)
		{
			cout << answer[i];
		}
		cout << "\n";
		return ;
	}

	for(int i=index; i<alpha.size(); i++)
	{
		if(check[i]) continue;
		check[i] = true;
		answer += alpha[i];
		get_pwd(i + 1);
		check[i] = false;
		answer.pop_back();
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;
	for(int i=0; i<c; i++)
	{
		char al;
		cin >> al;
		alpha.push_back(al);
	}

	sort(alpha.begin(), alpha.end());
	get_pwd(0);

	return 0;
}
