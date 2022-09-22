#include <string>
#include <vector>

using namespace std;

int zeroCnt(int n)
{
    int cnt = 0;

    if(n == 0)
        return 0;
    if(n % 2 == 1)
        cnt++;
    return zeroCnt(n / 2) + cnt;
}

int solution(int n) {
    int answer = 0;
    int zero_cnt = zeroCnt(n);
    int num = n;

    while(1)
    {
        num++;
        int num_zero_cnt = zeroCnt(num);
        
        if(num_zero_cnt != zero_cnt)
            continue;
        else
            break;
    }
    return answer = num;
}
