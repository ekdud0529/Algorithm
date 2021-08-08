#include <bits/stdc++.h>
using namespace std;

char s[8][9];

int main(int argc, char** argv) {
	int i, k, cnt=0;
	for(i=0;i<8;i++) cin >> s[i];
	for(i=0;i<8;i++){
		for(k=0;k<8;k++){
			if(i%2==0){
				if(k%2==0&&s[i][k]=='F') cnt++;
			}
			else{
				if(k%2==1&&s[i][k]=='F') cnt++;	
			}
		}
	}
	cout << cnt;
	return 0;
}
