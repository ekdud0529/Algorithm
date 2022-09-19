#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long a[4000];
long long b[4000];
long long c[4000];
long long d[4000];
unsigned long long answer = 0;

bool Cmp(const long long& a, const long long& b)
{
	if (a > b) return true;
	else return false;
}

int	main(void)
{
	int  n;
	vector<long long> ab;
	vector<long long> cd;
	int ptr = 0;
	int ptr2 = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end(), Cmp);
	while ((ptr < ab.size()) && (ptr2 < cd.size()))
	{
		if (ab[ptr] + cd[ptr2] == 0)
		{
			long long ab_cnt = 0;
			long long cd_cnt = 0;
	
			while ((ptr + ab_cnt < ab.size()) && (ab[ptr] == ab[ptr + ab_cnt]))
			{
				ab_cnt++;
			}
			while ((ptr2 + cd_cnt < cd.size()) && (cd[ptr2] == cd[ptr2 + cd_cnt]))
			{
				cd_cnt++;
			}
			ptr += ab_cnt;
			ptr2 += cd_cnt;
			answer += (ab_cnt * cd_cnt);
		}
		else if (ab[ptr] + cd[ptr2] > 0)
			ptr2++;
		else ptr++;
	}
	cout << answer;
	return (0);
}
