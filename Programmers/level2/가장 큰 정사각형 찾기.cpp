#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    if(board.size() == 1 && board[0].size() == 1)
        return (board[0][0]);
    for(int i=1; i<board.size(); i++)
    {
        for(int j=1; j<board[0].size(); j++)
        {
            if(board[i][j] == 0) continue;
            board[i][j] = min(board[i-1][j], min(board[i-1][j-1], board[i][j-1])) + 1;
            if(answer < board[i][j])
                answer = board[i][j];
        }
    }
    answer *= answer;
    return answer;
}
