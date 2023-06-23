class Solution
{
    public int solution(int [][]board)
    {
        int answer = 0;

        if(board.length == 1 && board[0].length == 1)
            return (board[0][0]);
        for(int i=1; i<board.length; i++)
        {
            for(int j=1; j<board[0].length; j++)
            {
                if(board[i][j] == 0) continue;
                board[i][j] = 1 + 
                    Math.min(board[i-1][j], Math.min(board[i][j-1], board[i-1][j-1]));
                if(board[i][j] > answer)
                    answer = board[i][j];
            }
        }
        answer *= answer;
        return answer;
    }
}
