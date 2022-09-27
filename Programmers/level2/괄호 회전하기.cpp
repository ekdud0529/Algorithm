#include <string>
#include <stack>
using namespace std;

string moveX(int mov, string s)
{
    string str = "";
    
    if(mov == 0)
        return (s);
    for(int i=mov; i<s.size(); i++)
    {
        str += s[i];
    }
    for(int i=0; i < mov; i++)
    {
        str += s[i];
    }
    return (str);
}

int checkStr(string s)
{
    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) return (0);
            char c = st.top();
            st.pop();
            if(s[i] == ')')
            {
                if(c != '(')
                    return (0);
            }
            else if(s[i] == ']')
            {
                if(c != '[')
                    return (0);
            }
            else if(s[i] == '}')
            {
                if(c != '{')
                    return (0);
            }
        }
    }
    if(st.size())
        return (0);
    return (1);
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i< s.size(); i++)
    {
        string str = moveX(i, s);
        answer += checkStr(str);
    }
    return answer;
}
