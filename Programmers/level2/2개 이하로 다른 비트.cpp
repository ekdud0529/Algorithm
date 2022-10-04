#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long getNum(long long num)
{
    long long i = 1;

    while(1)
    {
        if((num & i) == 0)
        {
            num = num | i;
            i >>= 1;
            num = num & (~i);
            return (num);
        }
        i <<= 1;
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); i++)
    {
        answer.push_back(getNum(numbers[i]));
    }
    return answer;
}
