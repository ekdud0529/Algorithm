#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int> > pq;
	
	while(n--)
	{
		int num;
		cin >> num;
		if(num) pq.push(num);
		else
		{
			if(!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << 0 << "\n";
		}
	}
	return 0;
}
