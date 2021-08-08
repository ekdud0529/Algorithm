#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	set<int> st;
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		st.insert(a);
	}
	for(set<int>::iterator i=st.begin(); i!=st.end(); i++){
		printf("%d\n", *i);
	}
	return 0;
}
