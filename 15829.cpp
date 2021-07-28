#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long l=0, m=1234567891;
    string s;
    
    long long r = 1, sum=0;
    cin >> l >> s;
    
    for(int i=0; i<l; i++){
        sum += ((s[i]-'a'+1)*r)%m;
        r = (r*31)%m;
    }
    cout << sum%m;
    return 0;
}
