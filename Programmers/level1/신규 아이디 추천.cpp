#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0; i<=new_id.size(); i++)
    {
        if('A' <= new_id[i] && new_id[i] <= 'Z')
            answer += new_id[i] + 32;
        else if(!('a' <= new_id[i] && new_id[i] <= 'z') 
                && new_id[i] != '.' && new_id[i] != '_' && new_id[i] != '-'
                && !('0' <= new_id[i] && new_id[i] <= '9'))
            continue;
        else
            answer += new_id[i];
    }
    
    for(int i=0; i<=answer.size(); i++)
    {
        if(answer[i] == '.' && answer[i+1] == '.')
            {
                answer.erase(i, 1);
                i--;
            }
    }
    
    while(answer[0] == '.')
        answer.erase(0, 1);
    while(answer[answer.size()-1] == '.')
        answer.erase(answer.size()-1);
    
    if(answer.size() == 0)
        answer += 'a';
    
    if(answer.size() > 15)
        answer.erase(15);
    
    while(answer[answer.size()-1] == '.')
        answer.erase(answer.size()-1);
    
    if(answer.size() <= 2)
    {
        char ch = answer[answer.size()-1];
        while(answer.size() < 3)
        {
            answer += ch;
        }
    }
    return answer;
}
