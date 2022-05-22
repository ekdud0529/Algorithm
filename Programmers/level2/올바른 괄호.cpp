#include <string>
#include <iostream>
#include <queue>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> q;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
            q.push('(');
        else if(s[i] == ')')
        {
            if(q.front() == '(')
                q.pop();
            else if(q.empty())
            {
                answer = false;
                break;
            }
        }
    }
    if(!q.empty())
        answer = false;
    return answer;
}
