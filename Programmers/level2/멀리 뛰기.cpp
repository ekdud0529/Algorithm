#include <queue>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long fibo[2001];
    
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2; i<=n; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    }
    answer = fibo[n];
    return (answer % 1234567);
}
