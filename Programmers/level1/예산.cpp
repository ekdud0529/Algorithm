#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = d.size();
    long long sum = 0;
    
    sort(d.begin(), d.end());
    
    if(budget < d[0])
        return 0;
    
    for(int i=0; i<d.size(); i++)
    {
        sum += d[i];
    }
    
    if(sum <= budget)
        return answer;
    
    else
    {
        for(int i=d.size()-1; i>=0; i--)
        {
            sum -= d[i];
            answer--;
            if(sum <= budget)
            {
                break;
            }
        }
    }
    return answer;
}
