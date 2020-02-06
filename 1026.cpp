#include <bits/stdc++.h>
using namespace std;

int a[50], b[50];

int main() {
	int n, cnt=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) scanf("%d", &b[i]);
	for(int i=0; i<n; i++){
		int temp;
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i=0; i<n; i++){
		int temp;
		for(int j=i+1; j<n; j++){
			if(b[i]<b[j]){
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	for(int i=0; i<n; i++) cnt += a[i]*b[i];
	printf("%d", cnt);
	return 0;
}
