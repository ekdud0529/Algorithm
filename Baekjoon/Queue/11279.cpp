#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	priority_queue<int> pq;
	
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		
		if(x == 0)
		{
			if(pq.empty()) cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		
		else if(x > 0) pq.push(x);
	}
	
	return 0;
}
