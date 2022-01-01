#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=0; i<progresses.size(); i++)
    {
        progresses[i] = (100 - progresses[i]);
        if(progresses[i] % speeds[i] != 0)
        {
            progresses[i] /= speeds[i];
            progresses[i]++;
        }
        else progresses[i] /= speeds[i];
    }
    
    for(int i=0; i<progresses.size(); i++)
    {
        int cnt = 1;
        int j = i;
        for(int k=i+1; k<progresses.size(); k++)
        {
            if(progresses[i] >= progresses[k])
            {
                cnt++;
                j = k;
            }
            else break;
        }
        i = j;
        answer.push_back(cnt);
    }
    return answer;
}
