#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int n, s=0, i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		char std[101];
		scanf("%s %d", std, &s);
		if(s>=97&&s<=100){
			printf("%s A+\n", std);
		}
		else if(s>=90&&s<=96){
			printf("%s A\n", std);
		}
		else if(s>=87&&s<=89){
			printf("%s B+\n", std);
		}
		else if(s>=80&&s<=86){
			printf("%s B\n", std);
		}
		else if(s>=77&&s<=79){
			printf("%s C+\n", std);
		}
		else if(s>=70&&s<=76){
			printf("%s C\n", std);
		}
		else if(s>=67&&s<=69){
			printf("%s D+\n", std);
		}
		else if(s>=60&&s<=66){
			printf("%s D\n", std);
		}
		else {
			printf("%s F\n", std);
		}
	}
	return 0;
}
