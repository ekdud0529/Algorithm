#include <string>
#include <vector>

using namespace std;

void swap(string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    for(int i=0; i<strings.size()-1; i++)
    {
        for(int k=i+1; k<strings.size(); k++)
        {
            if(strings[i][n] > strings[k][n])
            {
                swap(strings[i], strings[k]);
            }
            
            else if(strings[i][n] == strings[k][n])
            {
                int j;
                for(j=0; strings[i][j] && strings[k][j]; j++)
                {
                    if(strings[i][j] > strings[k][j])
                    {
                        swap(strings[i], strings[k]);
                        break;
                    }
                    else if(strings[i][j] == strings[k][j]) continue;
                    else break;
                }
                if(!strings[k][j] && strings[i][j])
                {
                    swap(strings[i], strings[k]);
                }
            }
        }
    }
    
    for(string str : strings)
    {
        answer.push_back(str);
    }
    return answer;
}
