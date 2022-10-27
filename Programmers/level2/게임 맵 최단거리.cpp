#include<vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct User{
    int x, y;
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    queue<User> q;
    q.push({0, 0});
    
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if(maps[nx][ny] == 0) continue;
            if(maps[nx][ny] > 1) continue;
            maps[nx][ny] = maps[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if(maps[n][m] == 1) return (-1);
    return (maps[n][m]);
}
