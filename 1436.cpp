#include <bits/stdc++.h>
using namespace std;

int n, title[10000];

int main(int argc, char** argv) {
	int end=666, count=0;
	for(int i=0; i<10000; i++){
		if(count%1000 == 666){
			for(int j=0; j<1000 && i<10000; j++){
				title[i] = count*1000 + j;
				i++;
			}
			i--;
		}
		else if(count%100 == 66){
			for(int j=0; j<100 && i<10000; j++){
				title[i] = count*1000 + (end%10)*100+ j;
				i++;
			}
			i--;	
		}
		else if(count%10 ==6 ){
			for(int j=0; j<10 && i<10000; j++){
				title[i] = count*1000 + (end%100)*10 + j;
				i++;
			}
			i--;
		}
		else{
			title[i] = count*1000 + end;
		}
		count++;
	}
	
	cin >> n;
	cout << title[n-1];
	return 0;
}

