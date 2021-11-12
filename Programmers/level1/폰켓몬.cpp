#include <vector>
using namespace std;

bool check[200001];

int solution(vector<int> nums)
{
    vector<int> poc;
    int answer = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(!check[nums[i]])
        {
            check[nums[i]] = 1;
            poc.push_back(nums[i]);
        }
    }
    
    if(nums.size()/2 < poc.size())
        answer = nums.size()/2;
    else
        answer = poc.size();
    
    return answer;
}
