#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (1)
    {
        answer++;
        if(a < b && (a & 1))
            if(a + 1 == b)
                break;
        if(a > b && (b & 1))
            if(b + 1 == a)
                break;
        if((a & 1) == 1) a++;
        if((b & 1) == 1) b++;
        a /= 2;
        b /= 2;
    }
    return answer;
}
