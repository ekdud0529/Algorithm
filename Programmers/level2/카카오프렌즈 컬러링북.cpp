#include <vector>
using namespace std;

int visited[100][100];
int area_cnt;
int area_max;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt;

void dfs(int x, int y, int area, vector<vector<int>> picture)
{
    visited[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= picture.size() || ny < 0 || ny >= picture[0].size()) continue;
        if(picture[nx][ny] != area) continue;
        if(visited[nx][ny]) continue;
        dfs(nx, ny, area, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    
    area_cnt = 0;
    area_max = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = false;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(visited[i][j]) continue;
            if(picture[i][j] == 0) continue;
            area_cnt++;
            cnt = 0;
            dfs(i, j, picture[i][j], picture);
            if(cnt > area_max) area_max = cnt;
        }
    }
    answer.push_back(area_cnt);
    answer.push_back(area_max);
    return answer;
}
