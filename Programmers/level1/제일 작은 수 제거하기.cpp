#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1) 
    {
        answer.push_back(-1);
    }
    else
    {
        answer = arr;
        int index = 0;
        int min = arr[0];
        for(int i = 1; i<arr.size(); i++)
        {
            if(arr[i] < min)
            {
                index = i;
                min = arr[i];
            }
        }
        answer.erase(answer.begin()+index);
    }
    return answer;
}
