#include <iostream>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    for(int i=1; i<land.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            int tmp = land[i-1][j];
            land[i-1][j] = 0;
            land[i][j] += max(land[i-1][0], 
                          max(land[i-1][1], 
                          max(land[i-1][2], land[i-1][3])));
            land[i-1][j] = tmp;
        }
    }
    answer = max(land[land.size()-1][0], 
             max(land[land.size()-1][1], 
             max(land[land.size()-1][2], land[land.size()-1][3])));
    return answer;
}
