#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, char>> print;
    char find;
    int proc = 1;
    
    for(int i=0; i<priorities.size(); i++)
    {
        print.push_back(make_pair(priorities[i], 'A'+i));
    }
    find = print[location].second;
    
    while(print.size() > 0)
    {
        int max = 0, idx = 0;
        for(int i=0; i<print.size(); i++)
        {
            if(print[i].first > max)
            {
                max = print[i].first;
                idx = i;
            }
        }
        if(print[idx].second == find)
        {
            answer = proc;
            break;
        }
        for(int i=0; i<idx; i++)
        {
            print.push_back(print.front());
            print.erase(print.begin());
        }
        proc++;
        print.erase(print.begin());
    }
    return answer;
}
