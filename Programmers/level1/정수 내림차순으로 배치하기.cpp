#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    while(n)
    {
        num.push_back(n%10);
        n /= 10;
    }
    for(int i=0; i<num.size()-1; i++)
    {
        for(int k=i+1; k<num.size(); k++)
        {
            if(num[i] > num[k])
            {
                int tmp = num[i];
                num[i] = num[k];
                num[k] = tmp;
            }
        }
    }
    for(int i=num.size()-1; i>=0; i--)
    {
        answer = answer*10 + num[i];
    }
    return answer;
}
