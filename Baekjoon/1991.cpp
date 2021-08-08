#include <bits/stdc++.h>
using namespace std;

void pre(vector<vector<int> > tree, int pos){
	printf("%c", pos+'A');
	if(tree[pos][0]!=-1) pre(tree, tree[pos][0]);
	if(tree[pos][1]!=-1) pre(tree, tree[pos][1]);	
}

void in(vector<vector<int> > tree, int pos){
	if(tree[pos][0]!=-1) in(tree, tree[pos][0]);
	printf("%c", pos+'A');
	if(tree[pos][1]!=-1) in(tree, tree[pos][1]);
}

void post(vector<vector<int> > tree, int pos){
	if(tree[pos][0]!=-1) post(tree, tree[pos][0]);
	if(tree[pos][1]!=-1) post(tree, tree[pos][1]);
	printf("%c", pos+'A');
}

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	vector<vector<int> > tree(n+1);
	for(int i=0; i<n; i++){
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		if(b=='.') tree[a-'A'].push_back(-1);
		else tree[a-'A'].push_back(b-'A');
		if(c=='.') tree[a-'A'].push_back(-1);
		else tree[a-'A'].push_back(c-'A');
	}
	pre(tree, 0);
	printf("\n");
	in(tree, 0);
	printf("\n");
	post(tree, 0);
	return 0;
}
