#include <string>
#include <vector>
using namespace std;

bool visited[5000];
int max_cnt = 0;

void bfs(int k, vector<vector<int>> dung, int cnt)
{
    if(cnt > max_cnt)
        max_cnt = cnt;
    for(int i=0; i<dung.size(); i++)
    {
        if(visited[i]) continue;
        if(k < dung[i][0]) continue;
        visited[i] = true;
        bfs(k - dung[i][1], dung, cnt + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    bfs(k, dungeons, 0);
    answer = max_cnt;
    return answer;
}
