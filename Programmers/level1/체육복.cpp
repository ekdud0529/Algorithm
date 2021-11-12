#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void del_overlap(vector<int> *lost, vector<int> *reserve, int *answer)
{
    for(int i=0; i < reserve -> size(); i++)
    {
        int index = 0;
        while(index < lost -> size())
        {
            if((*lost)[index] == (*reserve)[i])
            {
                lost -> erase(lost -> begin() + index);
                reserve -> erase(reserve -> begin() + i);
                *answer += 1;
                i--;
                index++;
                break;
            }
            index++;
        }
    }
}

bool check[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    del_overlap(&lost, &reserve, &answer);
    
    for(int i=0; i<reserve.size(); i++)
    {
        int index = 0;
        while(index < lost.size())
        {
            if(((reserve[i]+1 == lost[index]) || (reserve[i]-1 == lost[index]))
               && !(check[lost[index]]))
            {
                check[lost[index]] = 1;
                answer++;
                index++;
                break;
            }
            index++;
        }
    }
    return answer;
}
