#include <string>
#include <vector>

using namespace std;

int check_divisor(int num)
{
    int cnt = 0;
    
    for(int i=1; i <= num; i++)
    {
        if(num % i == 0)
            cnt++;
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    int cnt;
    
    while (left <= right)
    {
        cnt = check_divisor(left);
        if(cnt % 2 == 0)
            answer += left;
        else
            answer -= left;
        left++;
    }
    
    return answer;
}
