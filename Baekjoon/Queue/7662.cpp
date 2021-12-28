#include <bits/stdc++.h>
using namespace std;

bool check[1000000];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> k;
		int cnt = 0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > maxpq;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minpq;
		
		for(int j=0; j<k ;j++)
		{
			char op;
			int num;
			cin >> op >> num;
			
			if(op == 'I')
			{
				minpq.push({num, j});
				maxpq.push({num, j});
				check[j] = true;
				cnt++;
			}
			
			else if(op == 'D')
			{
				if(cnt == 0) continue;
				if(num == 1)
				{
					while(!check[maxpq.top().second]) maxpq.pop();
					check[maxpq.top().second] = false;
					maxpq.pop();
					cnt--;
				}
				else if(num == -1)
				{
					while(!check[minpq.top().second]) minpq.pop();
					check[minpq.top().second] = false;
					minpq.pop();
					cnt--;
				}
			}
		}
		
		if(cnt == 0) cout << "EMPTY\n";
		else
		{
			while(!check[maxpq.top().second]) maxpq.pop();
			while(!check[minpq.top().second]) minpq.pop();
			cout << maxpq.top().first << " " << minpq.top().first << "\n";
		}
	}
	
	return 0;
}
