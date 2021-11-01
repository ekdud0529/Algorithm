#include <vector>
#include <iostream>
using namespace std;

int check_prime(int num)
{
    int i;
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    for(i=2; i*i <= num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    int num;

    for(int i=0; i < nums.size()-2; i++)
    {
        for(int j=i+1; j < nums.size()-1; j++)
        {
            for(int k=j+1; k < nums.size(); k++)
            {
                num = nums[i] + nums[j] + nums[k];
                answer += check_prime(num);
            }
        }
    }

    return answer;
}
