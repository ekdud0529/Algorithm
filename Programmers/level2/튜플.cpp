#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

bool Cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second > b.second)
        return (true);
    else
        return (false);
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> tup;
    vector<pair<int, int>> tp;
    int num = 0;
    
    for(int i=1; i<s.size()-1; i++)
    {
        if(s[i] == '{') continue;
        if(s[i] == ',' || s[i] == '}')
        {
            if(num == 0) continue;
            if(!tup[num]) 
                tup[num] = 1;
            else 
                tup[num] += 1;
            num = 0;
        }
        else
        {
            num = (num * 10) + (s[i] - '0');
        }
    }
    for(auto iter = tup.begin(); iter != tup.end(); iter++)
    {
        tp.push_back({iter->first, iter->second});
    }
    sort(tp.begin(), tp.end(), Cmp);
    for(int i=0; i<tp.size(); i++)
    {
        answer.push_back(tp[i].first);
    }
    return answer;
}
