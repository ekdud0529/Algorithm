#include <bits/stdc++.h>
using namespace std;

int total_cnt = -1;

static void mk_num(long long a, int b, int cnt)
{
	if(a == b)
	{
		total_cnt = cnt;
		return ;	
	}
	if(a > b) return;
	mk_num(a*2, b, cnt+1);
	mk_num((a*10)+1, b, cnt+1);
}
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	mk_num(a, b, 1);
	cout << total_cnt;
	return 0;
}
