#include <bits/stdc++.h>
using namespace std;

int num[1024][1024];
int sum[1024 * 1024];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> num[i][j];
			sum[(n*i)+j] += (num[i][j] + sum[(n*i)+j-1]);
		}
	}
	
	while(m--)
	{
		pair<int, int> start;
		pair<int, int> end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		start.first--; start.second--;
		end.first--; end.second--;
		
		int total_sum = 0;
		for(int i=start.first; i<=end.first; i++)
		{
			total_sum += (sum[(n*i)+end.second] - sum[(n*i)+start.second-1]);
		}
		cout << total_sum << "\n";
	}
	
	return 0;
}
