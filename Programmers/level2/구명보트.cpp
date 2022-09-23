#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int a = 0;
    int b = people.size() - 1;
    
    sort(people.begin(), people.end());
    while(a <= b)
    {
        if(a == b)
        {
            answer++;
            break;
        }
        else if(people[a] + people[b] <= limit)
        {
            answer++;
            a++;
            b--;
        }
        else
        {
            answer++;
            b--;
        }
    }
    return answer;
}
