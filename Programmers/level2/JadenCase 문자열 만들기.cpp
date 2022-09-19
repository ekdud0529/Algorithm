#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = s;
    int index = 0;
    
    for(int i=0; i<answer.size(); i++)
    {
        if(s[i] == ' ')
        {
            index = 0;
        }
        else if (index == 0)
        {
            index = 1;
            if('a' <= answer[i] && answer[i] <= 'z')
            {
                answer[i] -= 32;
            }
        }
        else if('A' <= answer[i] && answer[i] <= 'Z')
        {
            answer[i] += 32;
        }
    }
    return answer;
}
