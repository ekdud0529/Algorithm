#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<char>> block;
vector<pair<int, int>> del;

void makeBlock(vector<string> board)
{
    int size = board.size();
    
    for(int j=0; j<board[0].size(); j++)
    {
        vector<char> v;
        for(int i=size-1; i>=0; i--)
        {
            v.push_back(board[i][j]);
        }
        block.push_back(v);
    }
}

void findFour(int n)
{
    int dx[3] = {1, 1, 0};
    int dy[3] = {0, 1, 1};

    for(int i=0; i<block.size(); i++)
    {
        for(int j=0; j<block[i].size(); j++)
        {
            bool flag = true;
            for(int k=0; k<3; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if((ny >= block[nx].size()) || (nx >= block.size()) || (block[i][j] != block[nx][ny]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                del.push_back({i, j});
                for(int k=0; k<3; k++)
                {
                    del.push_back({i + dx[k], j + dy[k]});
                }
            }
        }
    }
}

bool CMP(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
        return (true);
    else if(a.first == b.first)
    {
        if(a.second > b.second)
            return (true);
        else
            return (false);
    }
    return (false);
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    makeBlock(board);
    while (1)
    {
        del.clear();
        findFour(n);
        if(del.size() == 0) break;
        sort(del.begin(), del.end(), CMP);
        del.erase(unique(del.begin(), del.end()), del.end());
        answer += del.size();
        for(int i=0; i<del.size(); i++)
        {
            int x = del[i].first;
            int y = del[i].second;
            block[x].erase(block[x].begin() + y);
        }
    }
    return answer;
}
