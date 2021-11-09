#include <string>
#include <vector>

using namespace std;

vector<int> basket;

int get_doll(vector<vector<int>> board, int pos)
{
    int size = board.size();
    for(int i=0; i<size; i++)
    {
        if(board[i][pos-1] != 0)
        {
            basket.push_back(board[i][pos-1]);
            return i;
        }
    }
    return -1;
}

int ch_overlap()
{
    int size = basket.size();
    if(basket.size() >= 2)
    {
        if(basket[size - 1] == basket[size - 2])
        {
            basket.erase(basket.end()-2, basket.end());
            return 1;
        }
    }
    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int pos;
    for(int i=0; i < moves.size(); i++)
    {
        pos = get_doll(board, moves[i]);
        if(pos == -1) 
            continue;
        board[pos][moves[i]-1] = 0;
        if(ch_overlap())
            answer += 2;
    }
    return answer;
}
