#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string mkDup(int i, int cut, string s)
{
    string dup = "";

    for(int j=i; j<i + cut; j++)
    {
        dup += s[j];
    }
    return (dup);
}

int zipStr(int cut, string s)
{
    string ans = "";

    for(int i=0; i<s.size(); i++)
    {
        if(i + cut - 1 >= s.size())
        {
            ans += s[i];
            continue;
        }
        string dup = mkDup(i, cut, s);
        int cnt = 0;
        for(int j=i; j<s.size(); j++)
        {
            bool flag = true;
            for(int k=0; k<cut; k++)
            {
                if(dup[k] != s[j+k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cnt++;
                j += cut - 1;
            }
            else break;
        }
        if(cnt == 1)
        {
            ans += dup;
            i += cut - 1;
        }
        else
        {
            string num = "";
            i += (cnt * dup.size()) - 1;
            while(cnt)
            {
                num += (cnt % 10) + '0';
                cnt /= 10;
            }
            reverse(num.begin(), num.end());
            ans += num;
            ans += dup;
        }
    }
    return (ans.size());
}

int solution(string s) {
    int answer = s.size();
    
    for(int i=1; i<s.size(); i++)
    {
        int len = zipStr(i, s);
        if(len < answer) answer = len;
    }
    return answer;
}
