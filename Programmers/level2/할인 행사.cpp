#include <string>
#include <vector>
using namespace std;

int findIndex(vector<string> want, string s)
{
    for(int i=0; i<want.size(); i++)
    {
        if(want[i] == s)
        {
            return (i);
        }
    }
    return (-1);
}

bool checkAllGet(vector<int> number)
{
    for(int num : number)
    {
        if(num != 0)
            return (false);
    }
    return (true);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int left = 0;
    int right = 9;
    int index = 0;
    
    for(int i=0; i<10; i++)
    {
        index = findIndex(want, discount[i]);
        if(index == -1) continue;
        number[index] -= 1;
    }
    while(right < discount.size())
    {
        if(checkAllGet(number))
            answer += 1;
        index = findIndex(want, discount[left]);
        if(index != -1) number[index] += 1;
        left++;
        right++;
        if(right == discount.size()) break;
        index = findIndex(want, discount[right]); 
        if(index != -1) number[index] -= 1;
    }
    return answer;
}
