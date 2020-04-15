#include <bits/stdc++.h>
using namespace std;

long long c;

void add(int n){
	c |= (1<<n);
}

void remove(int n){
	c ^= (1<<n);
}

int check(int n){
	if(c&(1<<n)) return 1;
	else return 0;
}

void toggle(int n){
	if(c&(1<<n)) c^=(1<<n);
	else c|=(1<<n);
}

void all(){
	for(int i=0; i<21; i++) c|=(1<<i);
}

void empty(){
	for(int i=0; i<21; i++) c&=(0<<i);
}

int main(int argc, char** argv) {
	int n, x;
	char s[7];
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s %d", s, &x);
		if(!strcmp(s, "add")) add(x);
		else if(!strcmp(s, "remove")) remove(x);
		else if(!strcmp(s, "check")) printf("%d\n", check(x));
		else if(!strcmp(s, "toggle")) toggle(x);
		else if(!strcmp(s, "all")) all();
		else empty();
	}
	return 0;
}
