#include <bits/stdc++.h>
using namespace std;

bool numbers[13];
int num[13];
int k;
vector<int> lotto;

void get_num(int index, int cnt)
{
	if(cnt == 6)
	{
		for(int i=0; i<6; i++)
		{
			cout << lotto[i];
			if(i < k-1) cout << " ";
		}
		cout << "\n";
		return ;
	}
	
	for(int i=index; i<k; i++)
	{
		if(numbers[i]) continue;
		numbers[i] = true;
		lotto.push_back(num[i]);
		get_num(i + 1, cnt + 1);
		lotto.pop_back();
		numbers[i] = false;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	while(k != 0)
	{	
		for(int i=0; i<k; i++)
		{
			cin >> num[i];
		}
		
		get_num(0, 0);
		cout << "\n";
		cin >> k;
	}
	return 0;
}
