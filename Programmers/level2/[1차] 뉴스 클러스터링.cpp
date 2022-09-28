#include <string>
#include <vector>
using namespace std;

string makeLower(string s)
{
    string str = "";

    for(int i=0; i<s.size(); i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
        {
            str += (s[i] + 32);
        }
        else
        {
            str += s[i];
        }
    }
    return (str);
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;

    str1 = makeLower(str1);
    str2 = makeLower(str2);
    for(int i=0; i<str1.size() - 1; i++)
    {
        if('a' > str1[i] || str1[i] > 'z') continue;
        if('a' > str1[i + 1] || str1[i + 1] > 'z') continue;
        string st1(str1.begin() + i, str1.begin() + (i + 2));
        s1.push_back(st1);
    }
    for(int i=0; i<str2.size() - 1; i++)
    {
        if('a' > str2[i] || str2[i] > 'z') continue;
        if('a' > str2[i + 1] || str2[i + 1] > 'z') continue;
        string st2(str2.begin() + i, str2.begin() + (i + 2));
        s2.push_back(st2);
    }
    if(s1.size() == 0 && s2.size() == 0)
        return (65536);
    int size = s1.size() + s2.size();
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            if(s1[i] == s2[j])
            {
                answer++;
                s1.erase(s1.begin() + i);
                s2.erase(s2.begin() + j);
                i--;
                j--;
                break;
            }
        }
    }
    answer = (answer * 65536) / (size - answer);
    return answer;
}
