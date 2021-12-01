#include <bits/stdc++.h>
using namespace std;

int c = 0;

void add(int n){
	c |= (1 << n);
}

void remove(int n){
	c &= ~(1 << n);
}

void check(int n){
	if(c & (1 << n)) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void toggle(int n){
	c ^= (1 << n);
}

void all(){
	c = (1 << 21)-1;
}

void empty(){
	c = 0;
}

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x = 0;
	string s = "";
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		if(s == "add")
		{
			cin >> x;
			add(x);
		}
		else if(s == "remove")
		{
			cin >> x;
			remove(x);
		}
		else if(s == "check")
		{
			cin >> x;
			check(x);
		}
		else if(s == "toggle")
		{
			cin >> x;
			toggle(x);
		}
		else if(s == "all") all();
		else empty();
	}
	return 0;
}
