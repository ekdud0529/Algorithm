#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n;
	cin >> n;
	
	while(n--)
	{
		int num;
		cin >> num;
		
		if(num == 0)
		{
			if(pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else pq.push({abs(num), num});
	}
	return 0;
}
