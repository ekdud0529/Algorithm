#include <iostream>
using namespace std;

int sushi[33000];
int visited[3001];
int answer = 0;

void GetMaxEat(int n, int k, int c)
{
	int cnt = 1;
	int start = 0;
	int end = k - 1;

	
	visited[c]++;
	for (int i = start; i <= end; i++)
	{
		if (!visited[sushi[i]])
			cnt++;
		visited[sushi[i]]++;
	}
	answer = cnt;
	while (end < (n + k - 1))
	{
		if (cnt > answer)
			answer = cnt;
		visited[sushi[start]]--;
		if (visited[sushi[start]] == 0)
			cnt--;
		start++;
		end++;
		if (visited[sushi[end]] == 0)
			cnt++;
		visited[sushi[end]]++;
	}
}

int	main(void)
{
	int n, d, k, c;
	int cnt = 0;

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> sushi[i];
	}
	for (int i = n; i < n + k - 1; i++)
	{
		sushi[i] = sushi[i - n];
	}
	GetMaxEat(n, k, c);
	cout << answer;
	return (0);
}
