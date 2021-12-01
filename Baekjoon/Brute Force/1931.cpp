#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> conf[100000];

int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> conf[i].second;
		cin >> conf[i].first;
	}

	sort(conf, conf+n);

	int cnt = 1;
	int done_time = conf[0].first;
	for(int i=1; i<n; i++)
	{
		if(done_time <= conf[i].second)
		{
			cnt++;
			done_time = conf[i].first;
		}
	}
	cout << cnt;
	return 0;
}
