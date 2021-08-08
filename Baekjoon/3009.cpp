#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int a, b;
	vector<int > x;
	vector<int > y;
	for(int i=0; i<3; i++){
		scanf("%d %d", &a, &b);
		x.push_back(a);
		y.push_back(b);
	}
	if(x[0]!=x[1]){
		if(x[0]!=x[2]) a = x[0];
		else a = x[1];
	}
	if(y[0]!=y[1]){
		if(y[0]!=y[2]) b = y[0];
		else b = y[1];
	}
	printf("%d %d", a, b);
	return 0;
}
