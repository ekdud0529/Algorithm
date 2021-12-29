#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		map<string, int> categ_cnt;
		for(int i=0; i<n; i++)
		{
			string clothing, categ;
			cin >> clothing >> categ;
			if(categ_cnt.find(categ) == categ_cnt.end())
			{
				categ_cnt.insert({categ, 1});
			}
			else categ_cnt[categ] += 1;
		}
		
		int sum = n;
		if(categ_cnt.size() > 1)
		{
			sum = 1;
			for(auto iter : categ_cnt)
			{
				sum *= iter.second+1;
			}
			sum -= 1;
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}
