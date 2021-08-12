#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int m, n, i, k;
	scanf("%d %d", &m, &n);
	for(i=m;i<=n;i++){
		if(i==1) continue;
		else if(i==2) printf("2\n");
		else if(i%2==0) continue;
		else{
			for(k=3;k*k<i;k+=2){
				if(i%k==0) break;
			}
			if(k*k>i) printf("%d\n", i);
		}
	}
	return 0;
}


// 에라토스테네스의 체
#include <bits/stdc++.h>
using namespace std;

bool num[1000001];

int main(){
	int n, m;
	cin >> n >> m;
	
	num[1] = true;
	for(int i=2; i<=m; i++){
		if(num[i] == true) continue;
		
		for(int j=i+i; j<=m; j+=i){
			num[j] = true;
		}
	}
	
	for(int i=n; i<=m; i++){
		if(num[i] == false) cout << i << "\n";
	}
	
	return 0;
}
