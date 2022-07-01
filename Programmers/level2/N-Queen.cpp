#include <string>
#include <vector>

using namespace std;

bool chess[12][12];
int cnt;

bool posCheck(int x, int y, int n)
{
    for(int i=0; i<n; i++)
    {
        if(chess[i][y]) return false;
    }
    for(int i=1; i<n; i++)
    {
        if(0 > x-i) break;
        if(0 > y-i) break;
        if(chess[x-i][y-i]) return false;
    }
    for(int i=1; i<n; i++)
    {
        if(x+i >= n) break;
        if(y+i >= n) break;
        if(chess[x+i][y+i]) return false;
    }
    for(int i=1; i<n; i++)
    {
        if(0 > x-i) break;
        if(y+i >= n) break;
        if(chess[x-i][y+i]) return false;
    }
    for(int i=1; i<n; i++)
    {
        if(x+i >= n) break;
        if(0 > y-i) break;
        if(chess[x+i][y-i]) return false;
    }
    return true;
}

void dfs(int queen, int n)
{
    if(queen == n)
    {
        cnt++;
        return ;
    }
    
    for(int i=0; i<n; i++)
    {
        if(chess[queen][i]) continue;
        if(!posCheck(queen, i, n)) continue;

        chess[queen][i] = true;
        dfs(queen + 1, n);
        chess[queen][i] = false;
    }
}

int solution(int n) {
    int answer = 0;
    
    dfs(0, n);

    return answer = cnt;
}
