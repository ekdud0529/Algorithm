#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> word;
    int index = 1;
    int turn = 1;
    
    answer.push_back(0);
    answer.push_back(0);
    word[words[0]] = 1;
    for(int i=1; i<words.size(); i++)
    {
        if(index / n == 1)
        {
            index = 0;
            turn++;
        }
        if(words[i][0] != words[i-1][words[i-1].size()-1])
        {
            answer[0] = index + 1;
            answer[1] = turn;
            break;
        }
        if(!word[words[i]])
        {
            word[words[i]] = 1;
        }
        else
        {
            answer[0] = index + 1;
            answer[1] = turn;
            break;
        }
        index++;
    }
    return answer;
}
