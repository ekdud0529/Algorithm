#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

map<string, vector<int>> participant;

string getStr(int *index, string s)
{
    string str = "";
    
    for(; *index<s.size(); (*index)++)
    {
        if(s[*index] == ' ')
        {
            break;
        }
        str += s[*index];
    }
    (*index)++;
    return (str);
}

int StrToInt(string score)
{
    int num = 0;
    
    for(char c : score)
    {
        num = (num * 10) + (c - '0');
    }
    return (num);
}

void mkPartic(string s)
{
    int index = 0;
    int score;
    vector<string> partic;
    vector<string> p;
    
    partic.push_back(getStr(&index, s));
    partic.push_back(getStr(&index, s));
    partic.push_back(getStr(&index, s));
    partic.push_back(getStr(&index, s));
    score = StrToInt(getStr(&index, s));
    p.push_back("-");
    p.push_back(partic[0]);
    for(int i=1; i<partic.size(); i++)
    {
        int size = p.size();
        for(int j=0; j<size; j++)
        {
            p.push_back(p[j] + partic[i]);
            p.push_back(p[j] + "-");
        }
        p.erase(p.begin(), p.begin() + size);
    }
    for(int i=0; i<p.size(); i++)
    {
        participant[p[i]].push_back(score);
    }
}

pair<string, int> mkQuery(string s)
{
    int index = 0;
    int score;
    string str = "";
    
    str += getStr(&index, s);
    index += 4;
    str += getStr(&index, s);
    index += 4;
    str += getStr(&index, s);
    index += 4;
    str += getStr(&index, s);
    score = StrToInt(getStr(&index, s));
    return {str, score};
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string s : info) mkPartic(s);
    for(auto it=participant.begin(); it!=participant.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    for(string s : query)
    {
        pair<string, int> q = mkQuery(s);
        int index = 0;
        int left = 0;
        int right = participant[q.first].size();
        while(left < right)
        {
            index = (left + right) / 2;
            if(participant[q.first][index] < q.second) left = index + 1;
            else right = index;
        }
        answer.push_back(participant[q.first].size() - right);
    }
    return answer;
}
