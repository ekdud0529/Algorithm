#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	string answer = "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	cin >> s;
	int dif = (s[1] - s[0] - '0');
	for (int i = 2; i < s.size(); i++)
	{
		if (s[i] - s[i - 1] - '0' != dif)
		{
			answer =  "흥칫뿡!! <(￣ ﹌ ￣)>";
			break;
		}
	}
	cout << answer;
	return 0;
}
