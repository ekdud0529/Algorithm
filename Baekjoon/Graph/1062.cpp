#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int				n, k;
int				maxCnt = 0;
vector<string>	words;
bool			check[26];

void	cntCanRead(void)
{
	int cnt = 0;

	for (int i = 0; i < words.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (check[words[i][j] - 'a'] == false)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	if (cnt > maxCnt)
		maxCnt = cnt;
}

void	countWord(int index, int cnt)
{
	if (cnt == k - 5)
	{
		cntCanRead();
		return ;
	}
	for (int i = index; i < 26; i++)
	{
		if (check[i]) continue;
		check[i] = true;
		countWord(i + 1, cnt + 1);
		check[i] = false;
	}
}

int	main(void)
{
	string str;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{	
		cin >> str;
		words.push_back(str);
		sort(words[i].begin(), words[i].end());
		words[i].erase(unique(words[i].begin(), words[i].end()), words[i].end());
	}
	if (k < 5)
		cout << "0";
	else
	{
		check['a' - 'a'] = true;
		check['n' - 'a'] = true;
		check['t' - 'a'] = true;
		check['i' - 'a'] = true;
		check['c' - 'a'] = true;
		countWord(0, 0);
		cout << maxCnt;
	}
	return (0);
}
