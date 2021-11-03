#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sign = 1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '-')
            sign *= -1;
        else if('0' <= s[i] && s[i] <= '9')
            answer = answer*10 + (s[i]-'0');
    }
    answer *= sign;
    return answer;
}
