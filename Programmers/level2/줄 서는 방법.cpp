#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long f[21];
    
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=20; i++)
    {
        f[i] = i * f[i-1];
    }
    for(int i=1; i<=n; i++)
    {
        answer.push_back(i);
    }
    k--;
    for(int i=1; i<=n; i++)
    {
        if(f[n-i] > k) continue;
        int index = (k / f[n - i]);
        k -= (f[n-i] * index);
        answer.insert(answer.begin() + i - 1, answer[i - 1 + index]);
        answer.erase(answer.begin() + index + i);
    }
    return answer;
}
