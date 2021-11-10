#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }
    if(answer.size() == 0)
    {
        answer.push_back(-1);
        return answer;
    }
    for(int i=0; i<answer.size()-1; i++)
    {
        for(int k=i+1; k<answer.size(); k++)
        {
            if(answer[i] > answer[k])
            {
                int tmp = answer[i];
                answer[i] = answer[k];
                answer[k] = tmp;
            }
        }
    }
    return answer;
}
