#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(long long a=0; a<=d; a+=k)
    {
        long long dist = (long long)d * (long long)d;
        long long x = a * a;
        long long y = sqrt(dist - x);
        answer += ((y / k) + 1);
    }
    return answer;
}
