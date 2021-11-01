#include <string>
#include <vector>

using namespace std;

int get_power(int num, int power)
{
    int n = 1;
    while(power--)
    {
        n *= num;
    }
    return n;
}

int solution(int n) {
    int answer = 0;
    int num[14];
    int i, k=0;
    
    for(i=0; n > 0; i++)
    {
        num[i] = n % 3;
        n /= 3;
    }
    for(int j = i-1; j >= 0; j--)
    {
        answer += (num[j])*get_power(3, k);
        k++;
    }
    
    return answer;
}
