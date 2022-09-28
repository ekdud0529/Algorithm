#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string makeK(int n, int k)
{
    string s = "";

    while(n)
    {
        s += ((n % k) + '0');
        n /= k;
    }
    reverse(s.begin(), s.end());
    return (s);
}

bool checkPrime(long long num)
{
    if(num < 2) return (false);
    for(long long i=2; i * i <= num; i++)
    {
        if((num % i) == 0)
        {
            return (false);
        }
    }
    return (true);
}

int cntPrime(string s)
{
    long long num = 0;
    int cnt = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '0' && num != 0)
        {
            if(checkPrime(num)) cnt++;
            num = 0;
        }
        else
        {
            num = (num * 10) + (s[i] - '0');
        }
    }
    if(checkPrime(num))
        cnt++;
    return (cnt);
}

int solution(int n, int k) {
    int answer = 0;
    
    answer = cntPrime(makeK(n, k));
    return answer;
}
