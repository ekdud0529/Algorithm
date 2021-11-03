#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0;
            answer += s[i];
            continue;
        }
        else if(idx%2 == 0)
        {
            if('a' <= s[i] && s[i] <= 'z')
                answer += (s[i] - 32);
            else
                answer += s[i];
        }
        else
        {
            if('A' <= s[i] && s[i] <= 'Z')
                answer += (s[i] + 32);
            else
                answer += s[i];
        }
        idx++;
    }
    return answer;
}
