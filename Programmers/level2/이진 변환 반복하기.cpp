#include <string>
#include <vector>
using namespace std;

void makeOne(vector<int> x, int *cnt, int *rm)
{
    int num;
    (*cnt)++;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] == 0)
        {
            x.erase(x.begin() + i);
            i--;
            (*rm)++;
        }
    }
    num = x.size();
    if(num == 1)
        return ;
    x.clear();
    while(num)
    {
        x.push_back(num % 2);
        num /= 2;
    }
    makeOne(x, cnt, rm);
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int rm = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '1')
            answer.push_back(1);
        else
            rm++;
    }
    makeOne(answer, &cnt, &rm);
    answer.clear();
    answer.push_back(cnt);
    answer.push_back(rm);
    return answer;
}
