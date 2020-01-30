#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	list<pair<int, int> > ball;
	int a;
	for(int i=1; i<=n; i++){
		scanf("%d", &a);
		ball.push_back(pair<int, int>(a, i));
	}
	list<pair<int, int> >::iterator it = ball.begin();
	int sd, ft;
	for(int i=0; i<n; i++){
		ft = it -> first;
		sd = it -> second;
		printf("%d ", sd);
		it = ball.erase(it);
		if(ball.size()==1){
			printf("%d", ball.begin() -> second);
			break;	
		}
		else if(ft > 0){
			for(int k=1; k<ft; k++){
				if(it==ball.end()) it = ball.begin();
				it++;
			}
		}	
		else if(ft < 0)
			while(ft++){
				if(it == ball.begin()) it = ball.end();
				it--;
			}
	}
	return 0;
}
