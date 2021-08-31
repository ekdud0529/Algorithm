#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int checkNum(int corCnt){
    if(corCnt == 6) return 1;
    else if(corCnt == 5) return 2;
    else if(corCnt == 4) return 3;
    else if(corCnt == 3) return 4;
    else if(corCnt == 2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cntC = 0;
    int cntZ = 0;
    
    for(int i=0; i<6; i++){
        if(lottos[i] == 0){
            cntZ++;
            continue;
        }
        for(int j=0; j<6; j++){
            if(lottos[i] == win_nums[j]){
                cntC++;
                break;
            }
        }
    }
    
    answer.push_back(checkNum(cntC + cntZ));
    answer.push_back(checkNum(cntC));
    
    return answer;
}
