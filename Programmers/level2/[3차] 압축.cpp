#include <string>
#include <vector>

using namespace std;

vector<string> dict;

int searchDict(string s)
{
    for(int i=0; i<dict.size(); i++)
    {
        if(dict[i] == s)
            return (i);
    }
    return (-1);
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=0; i<msg.size(); i++)
    {
        string s;
        int index = -1;
        int x = 1;
        s = msg[i];
        while(1)
        {
            s += msg[i + x];
            int idx = searchDict(s);
            if(idx != -1)
                index = idx;
            else
                break;
            x++;
        }
        if(s.size() > 2)
        {
            answer.push_back(27 + index);
            dict.push_back(s);
            i += s.size() - 2;
        }
        else
        {
            answer.push_back(msg[i] - 'A' + 1);
            dict.push_back(s);
        }
    }
    return answer;
}
