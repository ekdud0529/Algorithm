#include <bits/stdc++.h>
using namespace std;

int n;
int graph[100][100];

void floydwarshall()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				if(graph[j][i] && graph[i][k])
				{
					graph[j][k] = 1;
				}
			}
		}
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
		for(int k=0; k<n; k++)
		{
			cin >> graph[i][k];
		}
	}
	
	floydwarshall();
	
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
		{
			cout << graph[i][k] << " ";
		}
		cout << "\n";
	}
	return 0;
}
