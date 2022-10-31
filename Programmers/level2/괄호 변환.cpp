#include <string>
#include <vector>
#include <stack>
using namespace std;

bool CheckStr(string p)
{
    stack<char> open;
    
    for(char c : p)
    {
        if(c == '(')
            open.push(c);
        else
        {
            if(open.empty()) return (false);
            open.pop();
        }
    }
    return (true);
}

bool CheckBalance(string p)
{
    int left = 0;
    int right = 0;
    
    for(char c : p)
    {
        if(c == '(') left++;
        else right++;
    }
    if (left && right && (left == right))
        return (true);
    return (false);
}

string MkCorrect(string p)
{
    string  u = "";
    int     index = 0;
    
    if (p == "" || CheckStr(p)) return (p);
    while(!CheckBalance(u))
    {
        u += p[index++];
    }
    string v = "";
    for(int i=index; i<p.size(); i++)
        v += p[i];
    if(CheckStr(u))
    {
        return (u + MkCorrect(v));
    }
    string ans = "(" + MkCorrect(v) + ")";
    for(int i=1; i<u.size()-1; i++)
    {
        if(u[i] == '(') u[i] = ')';
        else u[i] = '(';
    }
    u.erase(u.begin());
    u.erase(u.end()-1);
    return (ans + u);
}

string solution(string p) {
    string answer = p;
    
    if (!CheckStr(p))
    {
        answer = MkCorrect(p);
    }
    return answer;
}
