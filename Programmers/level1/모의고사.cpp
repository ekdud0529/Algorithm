#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans_cnt[3] = {0, 0, 0};
    int p1[5] = {1, 2, 3, 4, 5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int max = 0;
    
    for(int i=0; i<answers.size(); i++)
    {
        if(p1[i % 5] == answers[i]) ans_cnt[0]++;
        if(p2[i % 8] == answers[i]) ans_cnt[1]++;
        if(p3[i % 10] == answers[i]) ans_cnt[2]++;
    }
    for(int i=0; i<3; i++)
    {
        if(max < ans_cnt[i]) max = ans_cnt[i];
    }
    for(int i=0; i<3; i++)
    {
        if(max == ans_cnt[i]) answer.push_back(i+1);
    }
    return answer;
}
