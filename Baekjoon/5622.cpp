#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int i, cnt=0, n, m;
	string str;
	cin >> str;
	n = str.size();
	for(i=0;i<n;i++){
		m = str[i]-'A';
		if(m>=0&&m<3) cnt+=3;
		else if(m>=3&&m<6) cnt+=4;
		else if(m>=6&&m<9) cnt+=5;
		else if(m>=9&&m<12) cnt+=6;
		else if(m>=12&&m<15) cnt+=7;
		else if(m>=15&&m<19) cnt+=8;
		else if(m>=19&&m<22) cnt+=9;
		else cnt+=10;
	}
	printf("%d", cnt);
	return 0;
}
