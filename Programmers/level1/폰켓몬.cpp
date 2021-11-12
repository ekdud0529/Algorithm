#include <vector>
using namespace std;

bool check[200001];

int solution(vector<int> nums)
{
    int answer = nums.size()/2;
    
    for(int i=0; i<nums.size(); i++)
    {
        if(!check[nums[i]])
        {
            check[nums[i]] = 1;
        }
        else
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    
    if(answer > nums.size())
        answer = nums.size();
    
    return answer;
}
