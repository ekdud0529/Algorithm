#include <bits/stdc++.h>
using namespace std;

bool check[10000];

int mk_l(int n)
{
	int num = ((n%1000)*10) + (n/1000);
	return (num);
}

int mk_r(int n)
{
	int num = (n/10) + ((n%10)*1000);
	return (num);
}

int mk_d(int n)
{
	n *= 2;
	if(n > 9999) return (n%10000);
	return (n);
}

int mk_s(int n)
{
	if(n == 0) return 9999;
	else return (n-1);
}

void reset()
{
	for(int i=0; i<10000; i++)
		check[i] = false;
}

string bfs(int n1, int n2)
{
	string str = "";
	queue<pair<int, string> > q;
	check[n1] = true;
	
	reset();
	
	q.push({n1, ""});
	while(!q.empty())
	{
		int num = q.front().first;
		string s = q.front().second;
		q.pop();
		
		if(n2 == num) return (s);
		
		int x = mk_d(num);
		if(x == n2)
			return(s + "D");
		else if(!check[x])
		{
			q.push({x, s+"D"});
			check[x] = true;
		}
		
		x = mk_r(num);
		if(x == n2)
			return(s + "R");
		else if(!check[x])
		{
			q.push({x, s+"R"});
			check[x] = true;
		}
		
		x = mk_l(num);
		if(x == n2)
			return(s + "L");
		else if(!check[x])
		{
			q.push({x, s+"L"});
			check[x] = true;
		}
		
		x = mk_s(num);
		if(x == n2)
			return(s + "S");
		else if(!check[x])
		{
			q.push({x, s+"S"});
			check[x] = true;
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		cout << bfs(n1, n2) << "\n";
	}
	return 0;
}
