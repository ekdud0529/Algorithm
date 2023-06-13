#include <string>
#include <vector>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    
    for(int i=x+1; i<=y; i++)
    {
        dp[i] = 1000001;
    }
    for(int i=x; i<=y; i++)
    {
        if(i + n <= y) dp[i + n] = min(dp[i] + 1, dp[i + n]);
        if(i * 2 <= y) dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        if(i * 3 <= y) dp[i * 3] = min(dp[i] + 1, dp[i * 3]);
    }
    if(dp[y] == 1000001)
        return (-1);
    answer = dp[y];
    return answer;
}
