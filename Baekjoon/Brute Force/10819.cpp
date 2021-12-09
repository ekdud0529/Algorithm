#include <bits/stdc++.h>
using namespace std;

int n;
int a[8];
bool check[8];
vector<int> arr;

int sum_max = 0;

void get_sum()
{
	int sum = 0;
	
	for(int i=0; i<n-1; i++)
	{
		sum += abs(arr[i] - arr[i+1]);
	}
	if(sum > sum_max)
	{
		sum_max = sum;
	}
}

void recurs(int index)
{
	if(index == n)
	{
		get_sum();
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if(check[i]) continue;
		check[i] = true;
		arr.push_back(a[i]);
		recurs(index+1);
		arr.pop_back();
		check[i] = false;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	recurs(0);
	
	cout << sum_max;
	
	return 0;
}
