#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n, b = m;
    if(n > m)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int rest = m;
    while(rest)
    {
        rest = n%m;
        n = m;
        m = rest;
    }
    answer.push_back(n);
    answer.push_back(a*(b/n));
    return answer;
}
