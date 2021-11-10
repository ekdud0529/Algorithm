#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for(int i=0; i<s.size(); i++)
    {
        if(answer[i] != ' ')
        {
            if(answer[i] < 'a')
            {
                answer[i] = 'A' + (answer[i] + n - 'A')%26;
            }
            else
                answer[i] = 'a' + (answer[i] + n - 'a')%26;
        }
    }
    return answer;
}
