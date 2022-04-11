#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
	if(dp[a][b][c] != 0)
		return (dp[a][b][c]);
		
	for(int i=a; i<=20; i++)
	{
		for(int j=b; j<=20; j++)
		{
			for(int k=c; k<=20; k++)
			{
				if ((i <= 0) || (j <= 0) || (k <= 0))
					dp[i][j][k] = 1;
				else if((a < b) && (b < c))
				{
					dp[i][j][k] = w(i, j, k-1) + w(i, j-1, k-1) - w(i, j-1, k);
				}
				else
				{
					dp[i][j][k] = w(i-1, j, k) + w(i-1, j-1, k) + w(i-1, j, k-1) - w(i-1, j-1, k-1);
				}
			}
		}
	}
	return (0);
}

int main(int argc, char** argv) {
	w(0, 0, 0);
	
	int a, b, c;
	while(1)
	{
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)
			break;
		else if (a<=0 || b<=0 || c<=0)
			cout << "w(" << a << ", " << b << ", "<< c << ") = " << 1 << "\n";
		else if((a > 20) || (b > 20) || (c > 20))
			cout << "w(" << a << ", " << b << ", "<< c << ") = " << dp[20][20][20] << "\n";
		else cout << "w(" << a << ", " << b << ", "<< c << ") = " << dp[a][b][c] << "\n";
	}
	return 0;
}
