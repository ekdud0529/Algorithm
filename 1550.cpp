#include <bits/stdc++.h>
using namespace std;

string s;

int main(int argc, char** argv) {
	int i, t, c=0, k=0;
	cin >> s;
	t = s.size();
	for(i=t-1;i>=0;i--){
		if(s[i]>='A') c+=(s[i]-'A'+10)*pow(16, k);
		else c+=(s[i]-'0')*pow(16, k);
		k++;
	}
	cout << c;
	return 0;
}
