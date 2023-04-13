#include <vector>
#include <iostream>
using namespace std;

int grid[1000][1000];
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, -1};

void SetNum(int n)
{
    int x = 0;
    int y = 0;
    int num = 1;
    
    for(int k=0; k<n; k++)
    {
        switch(k % 3)
        {
            case 0:
                for(int i=0; i<n; i++)
                {
                    if(grid[x][y] != 0)
                        break;
                    grid[x][y] = num;
                    x += dx[0];
                    y += dy[0];
                    num++;
                }
                x--;
                y++;
                break;
            case 1:
                for(int i=0; i<n; i++)
                {
                    if(grid[x][y] != 0)
                        break;
                    if(y >= grid[x][0])
                        break;
                    grid[x][y] = num;
                    num++;
                    x += dx[1];
                    y += dy[1];
                }
                y -= 2;
                x--;
                break;
            case 2:
                for(int i=0; i<n; i++)
                {
                    if(grid[x][y] != 0)
                        break;
                    grid[x][y] = num;
                    num++;
                    x += dx[2];
                    y += dy[2];
                }
                x+=2;
                y++;
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    
    SetNum(n);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            answer.push_back(grid[i - 1][j]);
        }
    }
    return answer;
}
    
