#include <bits/stdc++.h>
using namespace std;

char s[101];

int main(int argc, char** argv) {
	int l, i, cnt=0;
	scanf("%s", s);
	l = strlen(s);
	for(i=0;i<l;i++){
		if(s[i]=='c'){
			if(s[i+1]=='-'||s[i+1]=='='){
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if(s[i]=='s'||s[i]=='z'){
			if(s[i+1]=='='){
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if(s[i]=='n'||s[i]=='l'){
			if(s[i+1]=='j'){
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if(s[i]=='d'){
			if(s[i+1]=='z'&&s[i+2]=='='){
				cnt++;
				i+=2;
			}
			else if(s[i+1]=='-'){
				cnt++;
				i++;
			}
			else cnt++;
		}
		else cnt++;
	}
	printf("%d", cnt);
	return 0;
}
