# 1
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = ((((long long)count+1)*(long long)count)/2)*(long long)price;
    sum -= (long long)money;
    
    if(sum <= 0) answer = 0;
    else answer = sum;

    return answer;
}

# 2
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 1LL*(((count+1)*count)/2)*price;
    sum -= (long long)money;
    
    if(sum <= 0) answer = 0;
    else answer = sum;

    return answer;
}
