#include <string>
#include <vector>

using namespace std;

bool check[201];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int num;
    
    for(int i=0; i<numbers.size()-1; i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            num = numbers[i] + numbers[j];
            if(!check[num])
            {
                answer.push_back(num);
                check[num] = true;
            }
        }
    }
    
    for(int i=0; i < answer.size()-1; i++)
    {
        for(int j=i+1; j < answer.size(); j++)
        {
            if(answer[i] > answer[j])
            {
                int tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }
    
    return answer;
}
