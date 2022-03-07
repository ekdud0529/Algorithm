#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(vector<int> num, int target, int index, int sum)
{
    if(index == num.size())
    {
        if(sum == target) cnt++;
        return ;
    }
    
    dfs(num, target, index+1, sum+num[index]);
    dfs(num, target, index+1, sum-num[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0);
    answer = cnt;
    return answer;
}
