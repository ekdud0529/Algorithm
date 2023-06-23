#include <string>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    answer += number[0];
    for(int i=1; i<number.size(); i++)
    {
        if(k == 0)
        {
            for(int j=i; j<number.size(); j++)
            {
                answer += number[j];
            }
            break;
        }
        while (answer.size() != 0 && answer[answer.size() - 1] < number[i])
        {
            answer.erase(answer.end() - 1);
            k--;
            if(k == 0) break;
        }
        answer += number[i];
    }
    while(k != 0)
    {
        k--;
        answer.erase(answer.end() - 1);
    }
    return answer;
}
