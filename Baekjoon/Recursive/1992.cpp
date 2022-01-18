#include <bits/stdc++.h>
using namespace std;

int arr[64][64];

bool check_same(int x, int y, int size)
{
	int ch = arr[x][y];
	
	for(int i=x; i<x+size; i++)
	{
		for(int k=y; k<y+size; k++)
		{
			if(ch != arr[i][k])
			{
				return false;
			}
		}
	}
	return true;
}

void check_num(int x, int y, int size)
{
	bool ch = check_same(x, y, size);
	
	if(ch)
		{
			cout << arr[x][y];
			return ;
		}
	
	if(size == 2)
	{
		cout << "(" << arr[x][y] << arr[x][y+1] 
				<< arr[x+1][y] << arr[x+1][y+1] << ")";
		return ;
	}
	else
	{
		cout << "(";
		check_num(x, y, size/2);
		check_num(x, y+size/2, size/2);
		check_num(x+size/2, y, size/2);
		check_num(x+size/2, y+size/2, size/2);
		cout << ")";
	}
}

void mk_num(int index, string num)
{
	int len = num.size();
	for(int i=0; i<len; i++)
	{
		arr[index][i] = num[i] - '0';
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		string num;
		cin >> num;
		mk_num(i, num);
	}
	
	check_num(0, 0, n);
	
	return 0;
}
