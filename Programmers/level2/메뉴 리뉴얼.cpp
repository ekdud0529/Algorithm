#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> menu;
int max_cnt = 0;

void makeStr(int index, int cnt, string order, string s)
{
    if(s.size() == cnt)
    {
        if(!menu[s]) menu[s] = 1;
        else menu[s] += 1;
        if(max_cnt < menu[s]) max_cnt = menu[s];
        return ;
    }
    for(int i=index; i<order.size(); i++)
    {
        makeStr(i + 1, cnt, order, s + order[i]);
    }
}

vector<string> getCnt(int cnt, vector<string> orders)
{
    vector<string> ans;
    
    max_cnt = 0;
    menu.clear();
    for(string s : orders)
    {
        sort(s.begin(), s.end());
        makeStr(0, cnt, s, "");
    }
    for(auto it=menu.begin(); it != menu.end(); it++)
    {
        if(it -> second < 2) continue;
        if(it -> second == max_cnt)
        {
            ans.push_back(it -> first);
        }
    }
    return (ans);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int cnt : course)
    {
        vector<string> c = getCnt(cnt, orders);
        if(c.size() != 0)
            answer.insert(answer.end(), c.begin(), c.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}
