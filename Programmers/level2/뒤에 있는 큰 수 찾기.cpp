#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    int bignum = 0;
    
    for(int i=numbers.size()-1; i>=0; i--)
    {
        if(bignum <= numbers[i])
        {
            bignum = numbers[i];
            answer[i] = -1;
            continue;
        }
        for(int j=i+1; j<numbers.size(); j++)
        {
            if(numbers[i] < numbers[j])
            {
                answer[i] = numbers[j];
                break;
            }
            if(numbers[i] < answer[j])
            {
                answer[i] = answer[j];
                break;
            }
        }
    }
    return answer;
}
