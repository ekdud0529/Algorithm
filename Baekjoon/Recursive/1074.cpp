#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt = -1;
bool check;

void ch_z(int x, int y, int size)
{
	if(check) return ;
	
	if(size > 2)
	{
		int sum = (size*size)/4;
		
		if(r < x+size/2 && c < y+size/2) ch_z(x, y, size/2);
		else if(r < x+size/2 && c >= y+size/2)
		{
			cnt += sum;
			ch_z(x, y+size/2, size/2);
		}
		else if(r >= x+size/2 && c < y+size/2)
		{
			cnt += (sum*2);
			ch_z(x+size/2, y, size/2);
		}
		else if(r >= x+size/2 && c >= y+size/2)
		{
			cnt += (sum*3);
			ch_z(x+size/2, y+size/2, size/2);
		}
	}

	if(size == 1)
	{
		cnt++;
		if(x == r && y == c) check = true;
		return ;
	}

	if(size >= 2)
	{
		ch_z(x, y, size/2);
		ch_z(x, y+size/2, size/2);
		ch_z(x+size/2, y, size/2);
		ch_z(x+size/2, y+size/2, size/2);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> r >> c;
	
	int size = pow(2, n);
	
	ch_z(0, 0, size);
	
	cout << cnt;
	return 0;
}
