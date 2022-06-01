#include <iostream>
#include <vector>
using namespace std;

bool visited[26];

bool checkGroup(string word)
{
	for (int i = 0; i < 26; i++)
		visited[i] = false;

	for (int i = 0; i < word.size(); i++)
	{
		int index = word[i] - 'a';

		if (visited[index]) return false;
		
		visited[index] = true;
		for (int j = i+1; j < word.size(); j++)
		{
			if (word[i] == word[j])
				i++;
			else
				break;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (checkGroup(s))
			cnt++;
	}
	cout << cnt;
	return 0;
}
