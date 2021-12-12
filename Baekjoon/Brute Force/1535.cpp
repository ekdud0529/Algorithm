#include <bits/stdc++.h>
using namespace std;

int n, l[20], j[20];
int max_joy = 0;
bool meet[20];

void get_joy(int index, int health, int joy)
{
	if(health <= 0) return ;
	if(max_joy < joy) max_joy = joy;

	for(int i=index; i<n; i++)
	{
		if(meet[i]) continue;
		meet[i] = true;
		get_joy(i + 1, health - l[i], joy + j[i]);
		meet[i] = false;
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
		cin >> l[i];
	}
	for(int i=0; i<n; i++)
	{
		cin >> j[i];
	}
	
	for(int i=0; i<n; i++)
	{
		get_joy(i, 100, 0);
	}
	
	cout << max_joy;
	
	return 0;
}
