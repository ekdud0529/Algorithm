#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

long long n, k;
long long prime[100];

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	set<int> s;
	int cnt = 0;
	long long max_num = 0;

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> prime[i];
		pq.push(prime[i]);
		s.insert(prime[i]);
		max_num = max(max_num, prime[i]);
	}
	while (1)
	{
		long long min_num = pq.top();
		pq.pop();
		cnt++;
		if (cnt == n)
		{
			cout << min_num;
			break;
		}
		for (int i = 0; i < k; i++)
		{
			long long num = min_num * prime[i];
			if (pq.size() >= n && num >= max_num)
				continue;
			if (s.find(num) != s.end())
				continue;
			pq.push(num);
			s.insert(num);
			max_num = max(num, max_num);
		}
	}
	return (0);
}
