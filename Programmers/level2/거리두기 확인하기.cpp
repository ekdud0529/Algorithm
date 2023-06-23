#include <string>
#include <vector>

using namespace std;

bool checkCovid(vector<string> places)
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<bool>> visited(5, vector<bool> (5, false));
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(places[i][j] != 'P') continue;
            for(int k=0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    continue;
                if(visited[nx][ny] || places[nx][ny] == 'P')
                    return (false);
                if(places[nx][ny] == 'O')
                    visited[nx][ny] = true;
            }
        }
    }
    return (true);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<places.size(); i++)
    {
        if(checkCovid(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}
