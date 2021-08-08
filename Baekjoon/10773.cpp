#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    long long sum=0;
    stack<int> num;
    
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> n;
        if(n == 0) num.pop();
        else num.push(n);
    }
    
    while(!num.empty()){
        sum += num.top();
        num.pop();
    }
    
    cout << sum;
    return 0;
}
