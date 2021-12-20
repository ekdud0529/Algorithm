#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int n;

int get_press(int number)
{
	int front = 0, back = num.size();
	int mid;
	
	while(front <= back)
	{
		mid = (front + back) / 2;
		
		if(num[mid] == number)
		{
			break;
		}
		else if(num[mid] < number)
		{
			front = mid + 1;
		}
		else
		{
			back = mid - 1;
		}
	}
	return mid;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int number;
		cin >> number;
		num.push_back(number);
	}
	
	vector<int> coord(num.begin(), num.end());
	
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	
	for(int i=0; i<coord.size(); i++)
	{
		int press = get_press(coord[i]);
		cout << press << " ";
	}
	
	return 0;
}
