#include <string>
#include <vector>

using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", 
                  "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    string str = "";
    int i = 0;
    
    while (s[i])
    {
        if (s[i] && ('0' <= s[i] && s[i] <= '9'))
        {
            answer = answer*10 + (s[i] - '0');
            i++;
        }
        else
        {
            while(s[i] && !('0' <= s[i] && s[i] <= '9'))
            {
                str += s[i];
                int idx = 0;
                while(idx < 10)
                {
                    if(num[idx] == str)
                    {
                        answer = answer*10 + idx;
                        str = "";
                        break;
                    }
                    idx++;
                }
                i++;
            }
        }
    }
    return answer;
}
