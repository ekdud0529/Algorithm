#include <iostream>
using namespace std;

int solution(int n) {
    long long dp[5001];
    
    if (n % 2)
        return (0);
    dp[2] = 3;
    dp[4] = 11;
    for(int i=6; i<=n; i++)
    {
        dp[i] = ((4 * dp[i - 2]) - dp[i - 4] + 1000000007) % 1000000007;
    }
    return (dp[n] % 1000000007);
}
