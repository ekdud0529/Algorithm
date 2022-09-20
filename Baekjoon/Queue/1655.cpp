#include <iostream>
#include <queue>
#include <cmath>
using namespace std;



int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int mid = 100000;
	int num;
	int max_size = 0;
	int min_size = 0;
	priority_queue<int> minq;
	priority_queue<int, vector<int>, greater<int>> maxq;

	cin >> n;
	while(n--)
	{
		cin >> num;
		if (mid == 100000)
		{
			mid = num;
		}
		else if (num > mid)
		{
			maxq.push(num);
			max_size++;
		}
		else if (num <= mid)
		{
			minq.push(num);
			min_size++;
		}
		int size = max_size - min_size;
		if (size > 1)
		{
			minq.push(mid);
			min_size++;
			mid = maxq.top();
			maxq.pop();
			max_size--;
		}
		else if (size < 0)
		{
			maxq.push(mid);
			max_size++;
			mid = minq.top();
			minq.pop();
			min_size--;
		}
		cout << mid << "\n";
	}
	return (0);
}
