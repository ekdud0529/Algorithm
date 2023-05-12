#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Position {
    int x;
    int y;
    int cnt;
};

bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

Position FindPosition(char c, vector<string> maps)
{
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[i].size(); j++)
        {
            if(maps[i][j] == c)
            {
                return {i, j, 0};
            }
        }
    }
    return {-1, -1, -1};
}

int bfs(Position start, Position end, vector<string> maps)
{
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    queue<Position> q;
    
    q.push(start);
    while (!q.empty())
    {
        Position now = q.front();
        q.pop();
        if(now.x == end.x && now.y == end.y)
        {
            return (now.cnt);
        }
        for(int i=0; i<4; i++)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(0 > nx || nx >= sizeX || 0 > ny || ny >= sizeY)
                continue;
            if(visited[nx][ny] || maps[nx][ny] == 'X')
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny, now.cnt + 1});
        }
    }
    return (-1);
}

void Clear()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            visited[i][j] = false;
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    int ans = 0;
    
    Position player = FindPosition('S', maps);
    Position lever = FindPosition('L', maps);
    if(lever.x == -1) return (-1);
    ans = bfs(player, lever, maps);
    if(ans == -1) return (-1);
    answer += ans;
    Clear();
    Position exit = FindPosition('E', maps);
    if(exit.x == -1)
        return (-1);
    ans = bfs(lever, exit, maps);
    if(ans == -1) return (-1);
    answer += ans;
    return answer;
}
