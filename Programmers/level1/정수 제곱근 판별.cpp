#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if(n == 1)
        return 4;
    else
    {
        for(long long i=2; i<=n/i; i++)
        {
            if(n == i*i)
            {
                answer = (i+1)*(i+1);
                break;
            }
        }
    }
    return answer;
}
