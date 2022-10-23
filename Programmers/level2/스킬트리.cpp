#include <string>
#include <vector>
using namespace std;

bool check[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<string> tree;
    
    for(char c : skill)
    {
        check[c - 'A'] = true;
    }
    for(int i=0; i<skill_trees.size(); i++)
    {
        string str = "";
        for(int j=0; j<skill_trees[i].size(); j++)
        {
            if(check[skill_trees[i][j] - 'A'])
            {
               str += skill_trees[i][j]; 
            }
        }
        tree.push_back(str);
    }
    for(string sk : tree)
    {
        bool flag = true;
        for(int i=0; i<sk.size(); i++)
        {
            if(sk[i] != skill[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}
