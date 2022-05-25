#include <string>
#include <vector>
using namespace std;

int score[11];
int max_score[11];
int max_diff = 0;

int checkScore(vector<int> info)
{
    int apeach_score = 0;
    int ryan_score = 0;
    int check = 0;
    
    for(int i=0; i<=10; i++)
    {
        if (!score[i] && !info[10 - i])
            continue;
        else if (score[i] <= info[10 - i])
            apeach_score += i;
        else
            ryan_score += i;
    }
    return (ryan_score - apeach_score);
}

void shootArrow(int used, int index, int n, vector<int> info)
{
    if(used > n) return ;
    if(index == 11 && used < n) return;
    if(used == n)
    {
        int diff = checkScore(info);
        if(max_diff < diff)
        {
            max_diff = diff;
            for(int i=0; i<=10; i++)
            {
                max_score[i] = score[i];
            }
        }
        return ;
    }
    for(int j=n-used; j>=0; j--)
    {
        score[index] = j;
        shootArrow(used + j, index + 1, n, info);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    shootArrow(0, 0, n, info);
    
    if(max_diff == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        for(int i=10; i>=0; i--)
        {
            answer.push_back(max_score[i]);
        }
    }
    
    return answer;
}
