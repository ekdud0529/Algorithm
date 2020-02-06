#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > wh(5);

void left(int num){
	wh[num].push_back(wh[num][0]);
	wh[num].erase(wh[num].begin());
}

void right(int num){
	wh[num].insert(wh[num].begin(), wh[num][7]);
	wh[num].pop_back();
}

int main(int argc, char** argv) {
	int n, num, ck, sc=0, cnt=1;
	for(int i=1;i<=4;i++){
		for(int j=0; j<8; j++){
			char m;
			scanf(" %c", &m);
			wh[i].push_back(m-'0');
		}	
	}
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &num, &ck);
		if(num==1){
			if(wh[1][2]^wh[2][6]){
				if(wh[2][2]^wh[3][6]){
					if(wh[3][2]^wh[4][6]){
						if(ck>0) left(4);
						else right(4);
					}
					if(ck>0) right(3);
					else left(3);
				}
				if(ck>0) left(2);
				else right(2);
			}
			if(ck>0) right(1);
			else left(1);
		}
		else if(num==4){
			if(wh[4][6]^wh[3][2]){
				if(wh[3][6]^wh[2][2]){
					if(wh[2][6]^wh[1][2]){
						if(ck>0) left(1);
						else right(1);
					}
					if(ck>0) right(2);
					else left(2);
				}
				if(ck>0) left(3);
				else right(3);
			}
			if(ck>0) right(4);
			else left(4);
		}
		else if(num==3){
			if(wh[3][2]^wh[4][6]){
				if(ck>0) left(4);
				else right(4);
			}
			if(wh[3][6]^wh[2][2]){
				if(wh[2][6]^wh[1][2]){
					if(ck>0) right(1);
					else left(1);
				}
				if(ck>0) left(2);
					else left(2);
			}
			if(ck>0) right(3);
			else left(3);
		}
		else{
			if(wh[2][6]^wh[1][2]){
				if(ck>0) left(1);
				else right(1);
			}
			if(wh[2][2]^wh[3][6]){
				if(wh[3][2]!=wh[4][6]){
					if(ck>0) right(4);
					else left(4);
				}
				if(ck>0) left(3);
				else right(3);
			}
			if(ck>0) right(2);
			else left(2);
		}
	}
	for(int i=1; i<=4; i++){
		if(wh[i][0]==1){
			sc+=cnt;
		}
		cnt*=2;
	}
	printf("%d", sc);
	return 0;
}
